#include "exec.h"
#include "utils.h"

#include <printf.h>
#include <scanf.h>

#include <stm32h7xx_hal.h>

DECL_CMD(md, "Hex dump memory")
{
    if (argc < 2) {
        printf("%s [addr] <count:32>\n", argv[0]);
        return -1;
    }
    uint32_t addr;
    if (sscanf(argv[1], "%li", &addr) != 1) {
        printf("Cannot parse address %s\n", argv[1]);
        return -1;
    }
    uint32_t count = 32;
    if (argc > 2) {
        if (sscanf(argv[2], "%li", &count) != 1) {
            printf("Cannot parse count %s\n", argv[2]);
            return -1;
        }
    }
    printf("Dump %ld bytes from 0x%08lX:\n", count, addr);
    hexdump((uint8_t*)addr, addr, count);
    return 0;
}

DECL_CMD(dfu, "Start DFU")
{
    (void)argc;
    (void)argv;
    HAL_DeInit();
    HAL_MspDeInit();
    /*
     * The datasheet say that bootloader start at 0x1FF0-0000 but a
     * memdump of this area show the bootloader is in 0x1FF0-9800
     */
    const uint32_t boot_addr = 0x1FF09800;
    const uint32_t* boot_vtor = (const uint32_t*)boot_addr;
    __set_MSP(boot_vtor[0]);
    __set_PSP(boot_vtor[0]);
    SCB->VTOR = boot_addr;
    __asm__ volatile("bx %[boot_pc]\n\t" ::[boot_pc] "r"(boot_vtor[1]));
    return -1;
}
