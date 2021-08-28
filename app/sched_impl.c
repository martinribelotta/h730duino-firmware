#include "sched.h"

#include <stm32h7xx_hal.h>

timestamp_t __sched_priv_get_tick(void)
{
    return HAL_GetTick();
}
