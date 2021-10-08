#include "utils.h"

#include <printf.h>
#include <stm32h7xx_hal.h>
#include <ctype.h>

void chexdump(const uint8_t* buf, size_t offset, size_t n, int columns)
{
    int rows = n / columns;
    int last_row = n % columns;
    for (int r = 0; r < rows; r++) {
        const uint8_t *row_ptr = buf + offset + (r * columns);
        printf("%08X: ", (intptr_t) row_ptr);
        bool is_last = (r == (rows - 1)) && (last_row > 0);
        for (int c = 0; c < columns; c++) {
            uint8_t data = row_ptr[c];
            if (is_last && c >= last_row) {
                printf("   ");
            } else {
                printf("%02X ", data);
            }
        }
        printf("|");
        for (int c = 0; c < columns; c++) {
            uint8_t data = row_ptr[c];
            if (is_last && c >= last_row) {
                printf(" ");
            } else {
                printf("%c", isgraph(data)? data : '.');
            }
        }
        printf("|\n");
    }
}

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
