#include <printf.h>

#include <stm32h7xx.h>

#include <main.h>
#include <sched.h>
#include <tusb.h>

typedef struct {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t retaddr;
    uint32_t xpsr;
} context_save_base_t;

typedef struct {
    context_save_base_t base;
    uint32_t s[16];
    uint32_t fpscr;
} context_save_ext_t;

static sched_entry_t aux_sched_list[2];
static sched_t aux_sched;
context_save_ext_t hardfault_ctx;

static void blink(void* ctx)
{
    (void)ctx;
    HAL_GPIO_TogglePin(USR_LED_GPIO_Port, USR_LED_Pin);
}
static void print_dot(void* ctx)
{
    (void) ctx;
    tud_cdc_write_char('.');
    tud_cdc_write_flush();
}

static void print_ctx(void)
{
    printf(
        " r0    = 0x%08lX\n"
        " r1    = 0x%08lX\n"
        " r2    = 0x%08lX\n"
        " r3    = 0x%08lX\n"
        " r12   = 0x%08lX\n"
        " lr    = 0x%08lX\n"
        " ret   = 0x%08lX\n"
        " xpsr  = 0x%08lX\n",
        hardfault_ctx.base.r0,
        hardfault_ctx.base.r1,
        hardfault_ctx.base.r2,
        hardfault_ctx.base.r3,
        hardfault_ctx.base.r12,
        hardfault_ctx.base.lr,
        hardfault_ctx.base.retaddr,
        hardfault_ctx.base.xpsr);
    if (__get_CONTROL() & (1 << 2)) {
        for (size_t i=0; i<TU_ARRAY_SIZE(hardfault_ctx.s); i++)
        printf(" S%-2d   = 0x%08lX\n", i, hardfault_ctx.s[i]);
        printf(" fpscr = 0x%08lX\n", hardfault_ctx.fpscr);
    }
}

void hardfault_manager(void)
{
    sched_init(&aux_sched, aux_sched_list, TU_ARRAY_SIZE(aux_sched_list));
    sched_scheduleEvery(&aux_sched, 50, sched_mkfunc(blink));
    sched_scheduleEvery(&aux_sched, 1000, sched_mkfunc(print_dot));
    int N = 3;
    printf("\nIn hardfault for %d sec.\n", N);
    print_ctx();
    uint32_t start = HAL_GetTick();
    while ((HAL_GetTick() - start) < (N * 1000UL)) {
        tud_task();
        sched_pool(&aux_sched);
    }
    HAL_NVIC_SystemReset();
}
