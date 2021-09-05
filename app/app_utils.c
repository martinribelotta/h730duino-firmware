#include "utils.h"

#include <printf.h>
#include <stm32h7xx_hal.h>

void hexdump(const uint8_t* buf, size_t offset, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        if ((i % 16) == 0) {
            if (i > 0) {
                printf("\n");
            }
            printf("%08X: ", i + offset);
        }
        printf("%02X ", buf[i]);
    }
    printf("\n");
}

int my_rand(void)
{
    extern RNG_HandleTypeDef hrng;
    uint32_t d;

    HAL_RNG_GenerateRandomNumber(&hrng, &d);

    return d;
}
