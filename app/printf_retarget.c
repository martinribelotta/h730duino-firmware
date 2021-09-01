#include <printf.h>

#include <tusb.h>

void _putchar(char character)
{
    while (tud_cdc_write_char(character) == 0) {
        tud_cdc_write_flush();
        tud_task();
    }
    if (character == '\n') {
        tud_cdc_write_flush();
        tud_task();
    }
}
