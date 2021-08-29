#include "exec.h"
#include "utils.h"

#include <fatfs.h>
#include <printf.h>
#include <string.h>

#define SD_CHECK(expr, err_expr)                                                   \
    do {                                                                           \
        FRESULT r = expr;                                                          \
        if (r != FR_OK) {                                                          \
            printf("SD Error %d (%s) on <<" #expr ">>\n", r, fatfs_err_to_str(r)); \
            err_expr;                                                              \
        }                                                                          \
    } while (0)

const char* fatfs_err_to_str(FRESULT r)
{
    switch (r) {
    case FR_OK:
        return "Succeeded";
    case FR_DISK_ERR:
        return "A hard error occurred in the low level disk I/O layer";
    case FR_INT_ERR:
        return "Assertion failed";
    case FR_NOT_READY:
        return "The physical drive cannot work";
    case FR_NO_FILE:
        return "Could not find the file";
    case FR_NO_PATH:
        return "Could not find the path";
    case FR_INVALID_NAME:
        return "The path name format is invalid";
    case FR_DENIED:
        return "Access denied due to prohibited access or directory full";
    case FR_EXIST:
        return "Access denied due to prohibited access";
    case FR_INVALID_OBJECT:
        return "The file/directory object is invalid";
    case FR_WRITE_PROTECTED:
        return "The physical drive is write protected";
    case FR_INVALID_DRIVE:
        return "The logical drive number is invalid";
    case FR_NOT_ENABLED:
        return "The volume has no work area";
    case FR_NO_FILESYSTEM:
        return "There is no valid FAT volume";
    case FR_MKFS_ABORTED:
        return "The f_mkfs() aborted due to any problem";
    case FR_TIMEOUT:
        return "Could not get a grant to access the volume within defined period";
    case FR_LOCKED:
        return "The operation is rejected according to the file sharing policy";
    case FR_NOT_ENOUGH_CORE:
        return "LFN working buffer could not be allocated";
    case FR_TOO_MANY_OPEN_FILES:
        return "Number of open files > _FS_LOCK";
    case FR_INVALID_PARAMETER:
        return "Given parameter is invalid";
    default:
        return "Unknown";
    }
}

FRESULT scan_files(char* path, bool recurse)
{
    FRESULT res;
    DIR dir;
    UINT i;
    static FILINFO fno;

    res = f_opendir(&dir, path); /* Open the directory */
    if (res == FR_OK) {
        for (;;) {
            res = f_readdir(&dir, &fno); /* Read a directory item */
            if (res != FR_OK || fno.fname[0] == 0)
                break; /* Break on error or end of dir */
            if ((fno.fattrib & AM_DIR) && recurse) { /* It is a directory */
                i = strlen(path);
                sprintf(&path[i], "/%s", fno.fname);
                res = scan_files(path, true); /* Enter the directory */
                if (res != FR_OK)
                    break;
                path[i] = 0;
            } else { /* It is a file. */
                printf("%s/%s\n", path, fno.fname);
            }
        }
        f_closedir(&dir);
    }

    return res;
}

static int sdcmd_df(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    FATFS* fs;
    DWORD n = 0;
    SD_CHECK(f_getfree(SDPath, &n, &fs), return -1);
    printf("Free space on SD %ld\n", n * 512);
    return 0;
}

static int sdcmd_ls(int argc, const char* const* argv)
{
    static char lspath[128];
    strcpy(lspath, "");
    bool recursive = false;
    for (int i = 2; i < argc; i++) {
        if (isEq(argv[i], "-r")) {
            recursive = true;
            break;
        } else {
            strcpy(lspath, argv[i]);
        }
    }
    printf("List directory %s\n", lspath);
    SD_CHECK(scan_files(lspath, recursive), return -1);
    return 0;
}

static void catfile(const char* file)
{
    SD_CHECK(f_open(&SDFile, file, FA_READ), return );
    while (!f_eof(&SDFile)) {
        static char buf[32];
        UINT readed = 0;
        SD_CHECK(f_read(&SDFile, buf, sizeof(buf), &readed), goto out);
        if (readed == 0) {
            break;
        }
        for (UINT i = 0; i < readed; i++)
            _putchar(buf[i]);
    }
    printf("\n");
out:
    f_close(&SDFile);
}

static int sdcmd_cat(int argc, const char* const* argv)
{
    for (int i = 2; i < argc; i++) {
        catfile(argv[i]);
    }
    return 0;
}

static int func_sd(int argc, const char* const* argv)
{
    static const struct {
        const char* cmd;
        const char* help;
        int (*func)(int argc, const char* const* argv);
    } subcommands[] = {
        { "df", "Show space free in disk", sdcmd_df },
        { "ls", "list directory: ls [dir]", sdcmd_ls },
        { "cat", "show file content: cat <file>", sdcmd_cat },
    };
    if (argc < 2 || isEq(argv[1], "help")) {
        printf("Usage: %s <subcommand> ...params...\n"
               "where <subcommand> can be one of:\n",
            argv[0]);
        FOREACH(e, subcommands)
        {
            printf(" %-20s %s\n", e->cmd, e->help);
        }
        return 0;
    }

    SD_CHECK(f_mount(&SDFatFS, SDPath, 0), return -1);
    int ret = -1;
    FOREACH(e, subcommands)
    {
        if (isEq(e->cmd, argv[1])) {
            ret = e->func(argc, argv);
            goto valid_out;
        }
    }
    printf("Unknown command %s\n", argv[1]);
valid_out:
    f_mount(&SDFatFS, NULL, 0);
    return ret;
}

static COMMAND_ENTRY(sd, func_sd, "sd commands");
