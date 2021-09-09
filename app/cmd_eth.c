#include "exec.h"
#include "stm32h7xx_hal.h"
#include "utils.h"
#include "lwip.h"
#include "printf.h"
#include "scanf.h"

DECL_CMD(phyrd, "Read ETH PHY reg")
{
    (void)argc;
    (void)argv;
    if (argc < 2) {
        printf("Usage: %s <reg>\n", argv[0]);
        return -1;
    }
    uint32_t reg;
    uint32_t val;
    if (sscanf(argv[1], "%li", &reg) != 1) {
        printf("Cannot parse: %s\n", argv[1]);
        return -1;
    }
    HAL_ETH_ReadPHYRegister(&heth, 0, reg, &val);
    printf("REG[0x%04lX] = %04lX\n", reg, val);
    return 0;
}

DECL_CMD(phywr, "Write ETH PHY reg")
{
    (void)argc;
    (void)argv;
    return 0;
}
