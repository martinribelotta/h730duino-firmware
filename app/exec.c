#include <exec.h>

#include <printf.h>
#include <stdbool.h>
#include <string.h>

#include <stm32h7xx.h>

#include "version.h"
#include "utils.h"

extern const exec_command_entry_t _begin_command_table;
extern const exec_command_entry_t _end_command_table;

int exec_commands(int argc, const char* const* argv)
{
    for (const exec_command_entry_t* e = &_begin_command_table;
         e < &_end_command_table;
         e++) {
        if (isEq(e->command, argv[0])) {
            return e->func(argc, argv);
        }
    }
    printf("Unknown command: %s\n", argv[0]);
    return -1;
}

static int func_help(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    printf("Command list:\n");
    for (const exec_command_entry_t* e = &_begin_command_table;
         e < &_end_command_table;
         e++) {
        printf(" %-20s %s\n", e->command, e->description);
    }
    return 0;
}

static const COMMAND_ENTRY(help, func_help, "Show this help");

static int func_reset(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    NVIC_SystemReset();
    return 0;
}

static const COMMAND_ENTRY(reset, func_reset, "Reset system");

static int func_version(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    printf("Version:\n%s\n", VERSION_STRING);
    return 0;
}

static const COMMAND_ENTRY(ver, func_version, "Show version");
