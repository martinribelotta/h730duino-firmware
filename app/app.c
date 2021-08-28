#include "SEGGER_RTT.h"
#include "exec.h"
#include "microrl.h"
#include "printf.h"
#include "qspi_ffi.h"
#include "tusb.h"
#include "sched.h"
#include "main.h"

static microrl_t rl;
static sched_t sched;
static sched_entry_t sched_list[10];

static void cdc_task(void)
{
    while (tud_cdc_available() > 0) {
        char c = tud_cdc_read_char();
        microrl_insert_char(&rl, c);
    }
}

static void cdc_print(const char* s)
{
    tud_cdc_write_str(s);
    tud_cdc_write_flush();
}

static void blink(void *ctx)
{
    (void) ctx;
    HAL_GPIO_TogglePin(USR_LED_GPIO_Port, USR_LED_Pin);
}

void setup()
{
    SEGGER_RTT_WriteString(0, "Hello World!\n");
    tusb_init();
    microrl_init(&rl, cdc_print);
    rl.execute = exec_commands;
    sched_init(&sched, sched_list, 10);
    sched_scheduleEvery(&sched, 250, SCHED_FUNCTOR(NULL, blink));
}

void loop()
{
    sched_pool(&sched);
    tud_task();
    cdc_task();
}

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
