#include "app.h"
#include "SEGGER_RTT.h"
#include "exec.h"
#include "main.h"
#include "microrl.h"
#include "printf.h"
#include "qspi_ffi.h"
#include "scanf.h"
#include "sched.h"
#include "tusb.h"
#include "utils.h"

static microrl_t rl;
static sched_t sched;
static sched_entry_t sched_list[10];
static sched_entry_t* blink_sched;

static void sched_task() { sched_pool(&sched); }

static void print_promt(void*)
{
    if (tud_cdc_connected())
        microrl_print_prompt(&rl);
    else
        sched_scheduleBefore(&sched, 200, sched_mkfunc(print_promt));
}

static void cdc_task(void)
{
    while (tud_cdc_available() > 0)
        microrl_insert_char(&rl, tud_cdc_read_char());
}

static void blink(void*)
{
    HAL_GPIO_TogglePin(USR_LED_GPIO_Port, USR_LED_Pin);
}

DECL_CMD(blink, "Change blinking time")
{
    if (argc < 2) {
        printf("Usage: %s <interval millis>\n", argv[0]);
        return 0;
    }
    int val;
    if (sscanf(argv[1], "%i", &val) != 1) {
        printf("Cannot parse number <<%s>>\n", argv[1]);
        return -1;
    }
    sched_scheduleEntryEvery(&sched, blink_sched, val, sched_mkfunc(blink));
    return 0;
}

void setup()
{
    SEGGER_RTT_WriteString(0, "Hello World!\n");
    tusb_init();
    microrl_init(&rl, [](const char* s) -> void {
        tud_cdc_write_str(s);
        tud_cdc_write_flush();
    });
    microrl_set_execute_callback(&rl, exec_commands);

    sched_init(&sched, sched_list, arraySize(sched_list));
    sched_scheduleBefore(&sched, 200, sched_mkfunc(print_promt));
    blink_sched = sched_scheduleEvery(&sched, 250, sched_mkfunc(blink));
}

void loop()
{
    sched_task();
    tud_task();
    cdc_task();
}
