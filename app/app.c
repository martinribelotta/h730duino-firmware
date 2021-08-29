#include "SEGGER_RTT.h"
#include "exec.h"
#include "microrl.h"
#include "printf.h"
#include "qspi_ffi.h"
#include "tusb.h"
#include "sched.h"
#include "main.h"
#include "scanf.h"

static microrl_t rl;
static sched_t sched;
static sched_entry_t sched_list[10];
static sched_entry_t *blink_sched;

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
    blink_sched = sched_scheduleEvery(&sched, 250, SCHED_FUNCTOR(NULL, blink));
}

static int func_blink(int argc, const char *const *argv)
{
    int val;
    if (argc < 2) {
        printf("Usage: %s <interval milis>\n", argv[0]);
        return 0;
    }
    if (sscanf(argv[1], "%i", &val) != 1) {
        printf("Cannot parse number <<%s>>\n", argv[1]);
        return -1;
    }
    sched_scheduleEntryEvery(&sched, blink_sched, val, SCHED_FUNCTOR(NULL, blink));
    return 0;
}

static COMMAND_ENTRY(blink, func_blink, "Change blinking time");

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
