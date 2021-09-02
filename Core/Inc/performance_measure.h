#ifndef __PERFORMANCE_MEASURE_H__
#define __PERFORMANCE_MEASURE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32h7xx.h>

#define DWT_DECL static __inline__ __attribute__((__always_inline__))

DWT_DECL void dwt_reset(void)
{
  CoreDebug->DEMCR |= 0x01000000UL;
  DWT->CYCCNT = 0UL;
  DWT->CTRL = 0UL;
}

DWT_DECL void dwt_start(void) { DWT->CTRL |= 1UL; }
DWT_DECL void dwt_stop(void) { DWT->CTRL &= ~1UL; }
DWT_DECL uint32_t dwt_cycles(void) { return DWT->CYCCNT; }

#ifdef __cplusplus
}
#endif

#endif // __PERFORMANCE_MEASURE_H__
