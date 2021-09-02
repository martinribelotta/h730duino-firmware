#include <stddef.h>
#include <stdint.h>

/*----------------------------------------------------------------------------
  Preprocessor Definitions
 *----------------------------------------------------------------------------*/
#define VTOR (*((volatile uint32_t *)0xE000ED08))
#define HANDLER_TRAILS __attribute__((weak, alias("Default_Handler")))
#define NORETURN __attribute__((__noreturn__))

/*----------------------------------------------------------------------------
  Type Definitions
 *----------------------------------------------------------------------------*/
typedef struct {
  uint32_t const *src;
  uint32_t *dest;
  uint32_t wlen;
} copy_table_t;

typedef struct {
  uint32_t *dest;
  uint32_t wlen;
} zero_table_t;

/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern const uint32_t __StackTop;
extern const copy_table_t __copy_table_start__;
extern const copy_table_t __copy_table_end__;
extern const zero_table_t __zero_table_start__;
extern const zero_table_t __zero_table_end__;

extern void SystemInit(void);
extern void __libc_init_array(void);
extern int main(void);

/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
NORETURN void Reset_Handler(void);
void Default_Handler(void);

/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler(void) HANDLER_TRAILS;
void HardFault_Handler(void) HANDLER_TRAILS;
void MemManage_Handler(void) HANDLER_TRAILS;
void BusFault_Handler(void) HANDLER_TRAILS;
void UsageFault_Handler(void) HANDLER_TRAILS;
void SVC_Handler(void) HANDLER_TRAILS;
void DebugMon_Handler(void) HANDLER_TRAILS;
void PendSV_Handler(void) HANDLER_TRAILS;
void SysTick_Handler(void) HANDLER_TRAILS;

void WWDG_IRQHandler(void) HANDLER_TRAILS;
void PVD_AVD_IRQHandler(void) HANDLER_TRAILS;
void TAMP_STAMP_IRQHandler(void) HANDLER_TRAILS;
void RTC_WKUP_IRQHandler(void) HANDLER_TRAILS;
void FLASH_IRQHandler(void) HANDLER_TRAILS;
void RCC_IRQHandler(void) HANDLER_TRAILS;
void EXTI0_IRQHandler(void) HANDLER_TRAILS;
void EXTI1_IRQHandler(void) HANDLER_TRAILS;
void EXTI2_IRQHandler(void) HANDLER_TRAILS;
void EXTI3_IRQHandler(void) HANDLER_TRAILS;
void EXTI4_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream0_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream1_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream2_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream3_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream4_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream5_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream6_IRQHandler(void) HANDLER_TRAILS;
void ADC_IRQHandler(void) HANDLER_TRAILS;
void FDCAN1_IT0_IRQHandler(void) HANDLER_TRAILS;
void FDCAN2_IT0_IRQHandler(void) HANDLER_TRAILS;
void FDCAN1_IT1_IRQHandler(void) HANDLER_TRAILS;
void FDCAN2_IT1_IRQHandler(void) HANDLER_TRAILS;
void EXTI9_5_IRQHandler(void) HANDLER_TRAILS;
void TIM1_BRK_IRQHandler(void) HANDLER_TRAILS;
void TIM1_UP_IRQHandler(void) HANDLER_TRAILS;
void TIM1_TRG_COM_IRQHandler(void) HANDLER_TRAILS;
void TIM1_CC_IRQHandler(void) HANDLER_TRAILS;
void TIM2_IRQHandler(void) HANDLER_TRAILS;
void TIM3_IRQHandler(void) HANDLER_TRAILS;
void TIM4_IRQHandler(void) HANDLER_TRAILS;
void I2C1_EV_IRQHandler(void) HANDLER_TRAILS;
void I2C1_ER_IRQHandler(void) HANDLER_TRAILS;
void I2C2_EV_IRQHandler(void) HANDLER_TRAILS;
void I2C2_ER_IRQHandler(void) HANDLER_TRAILS;
void SPI1_IRQHandler(void) HANDLER_TRAILS;
void SPI2_IRQHandler(void) HANDLER_TRAILS;
void USART1_IRQHandler(void) HANDLER_TRAILS;
void USART2_IRQHandler(void) HANDLER_TRAILS;
void USART3_IRQHandler(void) HANDLER_TRAILS;
void EXTI15_10_IRQHandler(void) HANDLER_TRAILS;
void RTC_Alarm_IRQHandler(void) HANDLER_TRAILS;
void TIM8_BRK_TIM12_IRQHandler(void) HANDLER_TRAILS;
void TIM8_UP_TIM13_IRQHandler(void) HANDLER_TRAILS;
void TIM8_TRG_COM_TIM14_IRQHandler(void) HANDLER_TRAILS;
void TIM8_CC_IRQHandler(void) HANDLER_TRAILS;
void DMA1_Stream7_IRQHandler(void) HANDLER_TRAILS;
void FMC_IRQHandler(void) HANDLER_TRAILS;
void SDMMC1_IRQHandler(void) HANDLER_TRAILS;
void TIM5_IRQHandler(void) HANDLER_TRAILS;
void SPI3_IRQHandler(void) HANDLER_TRAILS;
void UART4_IRQHandler(void) HANDLER_TRAILS;
void UART5_IRQHandler(void) HANDLER_TRAILS;
void TIM6_DAC_IRQHandler(void) HANDLER_TRAILS;
void TIM7_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream0_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream1_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream2_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream3_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream4_IRQHandler(void) HANDLER_TRAILS;
void ETH_IRQHandler(void) HANDLER_TRAILS;
void ETH_WKUP_IRQHandler(void) HANDLER_TRAILS;
void FDCAN_CAL_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream5_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream6_IRQHandler(void) HANDLER_TRAILS;
void DMA2_Stream7_IRQHandler(void) HANDLER_TRAILS;
void USART6_IRQHandler(void) HANDLER_TRAILS;
void I2C3_EV_IRQHandler(void) HANDLER_TRAILS;
void I2C3_ER_IRQHandler(void) HANDLER_TRAILS;
void OTG_HS_EP1_OUT_IRQHandler(void) HANDLER_TRAILS;
void OTG_HS_EP1_IN_IRQHandler(void) HANDLER_TRAILS;
void OTG_HS_WKUP_IRQHandler(void) HANDLER_TRAILS;
void OTG_HS_IRQHandler(void) HANDLER_TRAILS;
void DCMI_IRQHandler(void) HANDLER_TRAILS;
void CRYP_IRQHandler(void) HANDLER_TRAILS;
void HASH_RNG_IRQHandler(void) HANDLER_TRAILS;
void FPU_IRQHandler(void) HANDLER_TRAILS;
void UART7_IRQHandler(void) HANDLER_TRAILS;
void UART8_IRQHandler(void) HANDLER_TRAILS;
void SPI4_IRQHandler(void) HANDLER_TRAILS;
void SPI5_IRQHandler(void) HANDLER_TRAILS;
void SPI6_IRQHandler(void) HANDLER_TRAILS;
void SAI1_IRQHandler(void) HANDLER_TRAILS;
void LTDC_IRQHandler(void) HANDLER_TRAILS;
void LTDC_ER_IRQHandler(void) HANDLER_TRAILS;
void DMA2D_IRQHandler(void) HANDLER_TRAILS;
void SAI2_IRQHandler(void) HANDLER_TRAILS;
void QUADSPI_IRQHandler(void) HANDLER_TRAILS;
void LPTIM1_IRQHandler(void) HANDLER_TRAILS;
void CEC_IRQHandler(void) HANDLER_TRAILS;
void I2C4_EV_IRQHandler(void) HANDLER_TRAILS;
void I2C4_ER_IRQHandler(void) HANDLER_TRAILS;
void SPDIF_RX_IRQHandler(void) HANDLER_TRAILS;
void OTG_FS_EP1_OUT_IRQHandler(void) HANDLER_TRAILS;
void OTG_FS_EP1_IN_IRQHandler(void) HANDLER_TRAILS;
void OTG_FS_WKUP_IRQHandler(void) HANDLER_TRAILS;
void OTG_FS_IRQHandler(void) HANDLER_TRAILS;
void DMAMUX1_OVR_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_Master_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_TIMA_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_TIMB_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_TIMC_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_TIMD_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_TIME_IRQHandler(void) HANDLER_TRAILS;
void HRTIM1_FLT_IRQHandler(void) HANDLER_TRAILS;
void DFSDM1_FLT0_IRQHandler(void) HANDLER_TRAILS;
void DFSDM1_FLT1_IRQHandler(void) HANDLER_TRAILS;
void DFSDM1_FLT2_IRQHandler(void) HANDLER_TRAILS;
void DFSDM1_FLT3_IRQHandler(void) HANDLER_TRAILS;
void SAI3_IRQHandler(void) HANDLER_TRAILS;
void SWPMI1_IRQHandler(void) HANDLER_TRAILS;
void TIM15_IRQHandler(void) HANDLER_TRAILS;
void TIM16_IRQHandler(void) HANDLER_TRAILS;
void TIM17_IRQHandler(void) HANDLER_TRAILS;
void MDIOS_WKUP_IRQHandler(void) HANDLER_TRAILS;
void MDIOS_IRQHandler(void) HANDLER_TRAILS;
void JPEG_IRQHandler(void) HANDLER_TRAILS;
void MDMA_IRQHandler(void) HANDLER_TRAILS;
void SDMMC2_IRQHandler(void) HANDLER_TRAILS;
void HSEM1_IRQHandler(void) HANDLER_TRAILS;
void ADC3_IRQHandler(void) HANDLER_TRAILS;
void DMAMUX2_OVR_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel0_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel1_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel2_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel3_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel4_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel5_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel6_IRQHandler(void) HANDLER_TRAILS;
void BDMA_Channel7_IRQHandler(void) HANDLER_TRAILS;
void COMP1_IRQHandler(void) HANDLER_TRAILS;
void LPTIM2_IRQHandler(void) HANDLER_TRAILS;
void LPTIM3_IRQHandler(void) HANDLER_TRAILS;
void LPTIM4_IRQHandler(void) HANDLER_TRAILS;
void LPTIM5_IRQHandler(void) HANDLER_TRAILS;
void LPUART1_IRQHandler(void) HANDLER_TRAILS;
void CRS_IRQHandler(void) HANDLER_TRAILS;
void ECC_IRQHandler(void) HANDLER_TRAILS;
void SAI4_IRQHandler(void) HANDLER_TRAILS;
void WAKEUP_PIN_IRQHandler(void) HANDLER_TRAILS;

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

const void *__romVectors[] __attribute__((used, section(".isr_vector"))) = {
  (void *)(&__StackTop), /*     Initial Stack Pointer */
  Reset_Handler,         /*     Reset Handler         */
  NMI_Handler,           /* -14 NMI Handler           */
  HardFault_Handler,     /* -13 Hard Fault Handler    */
  MemManage_Handler,     /* -12 MPU Fault Handler     */
  BusFault_Handler,      /* -11 Bus Fault Handler     */
  UsageFault_Handler,    /* -10 Usage Fault Handler   */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  SVC_Handler,           /*  -5 SVCall Handler        */
  DebugMon_Handler,      /*  -4 Debug Monitor Handler */
  0,                     /*     Reserved              */
  PendSV_Handler,        /*  -2 PendSV Handler        */
  SysTick_Handler,       /*  -1 SysTick Handler       */
};

const void *__Vectors[] __attribute__((used, section(".dtcmvtor"))) = {
  (void *)(&__StackTop), /*     Initial Stack Pointer */
  Reset_Handler,         /*     Reset Handler         */
  NMI_Handler,           /* -14 NMI Handler           */
  HardFault_Handler,     /* -13 Hard Fault Handler    */
  MemManage_Handler,     /* -12 MPU Fault Handler     */
  BusFault_Handler,      /* -11 Bus Fault Handler     */
  UsageFault_Handler,    /* -10 Usage Fault Handler   */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  0,                     /*     Reserved              */
  SVC_Handler,           /*  -5 SVCall Handler        */
  DebugMon_Handler,      /*  -4 Debug Monitor Handler */
  0,                     /*     Reserved              */
  PendSV_Handler,        /*  -2 PendSV Handler        */
  SysTick_Handler,       /*  -1 SysTick Handler       */

  /* External Interrupts */
  WWDG_IRQHandler,               /* Window WatchDog                             */
  PVD_AVD_IRQHandler,            /* PVD/AVD through EXTI Line detection         */
  TAMP_STAMP_IRQHandler,         /* Tamper and TimeStamps through the EXTI line */
  RTC_WKUP_IRQHandler,           /* RTC Wakeup through the EXTI line            */
  FLASH_IRQHandler,              /* FLASH                                       */
  RCC_IRQHandler,                /* RCC                                         */
  EXTI0_IRQHandler,              /* EXTI Line0                                  */
  EXTI1_IRQHandler,              /* EXTI Line1                                  */
  EXTI2_IRQHandler,              /* EXTI Line2                                  */
  EXTI3_IRQHandler,              /* EXTI Line3                                  */
  EXTI4_IRQHandler,              /* EXTI Line4                                  */
  DMA1_Stream0_IRQHandler,       /* DMA1 Stream 0                               */
  DMA1_Stream1_IRQHandler,       /* DMA1 Stream 1                               */
  DMA1_Stream2_IRQHandler,       /* DMA1 Stream 2                               */
  DMA1_Stream3_IRQHandler,       /* DMA1 Stream 3                               */
  DMA1_Stream4_IRQHandler,       /* DMA1 Stream 4                               */
  DMA1_Stream5_IRQHandler,       /* DMA1 Stream 5                               */
  DMA1_Stream6_IRQHandler,       /* DMA1 Stream 6                               */
  ADC_IRQHandler,                /* ADC1, ADC2 and ADC3s                        */
  FDCAN1_IT0_IRQHandler,         /* FDCAN1 interrupt line 0                     */
  FDCAN2_IT0_IRQHandler,         /* FDCAN2 interrupt line 0                     */
  FDCAN1_IT1_IRQHandler,         /* FDCAN1 interrupt line 1                     */
  FDCAN2_IT1_IRQHandler,         /* FDCAN2 interrupt line 1                     */
  EXTI9_5_IRQHandler,            /* External Line[9:5]s                         */
  TIM1_BRK_IRQHandler,           /* TIM1 Break interrupt                        */
  TIM1_UP_IRQHandler,            /* TIM1 Update interrupt                       */
  TIM1_TRG_COM_IRQHandler,       /* TIM1 Trigger and Commutation interrupt      */
  TIM1_CC_IRQHandler,            /* TIM1 Capture Compare                        */
  TIM2_IRQHandler,               /* TIM2                                        */
  TIM3_IRQHandler,               /* TIM3                                        */
  TIM4_IRQHandler,               /* TIM4                                        */
  I2C1_EV_IRQHandler,            /* I2C1 Event                                  */
  I2C1_ER_IRQHandler,            /* I2C1 Error                                  */
  I2C2_EV_IRQHandler,            /* I2C2 Event                                  */
  I2C2_ER_IRQHandler,            /* I2C2 Error                                  */
  SPI1_IRQHandler,               /* SPI1                                        */
  SPI2_IRQHandler,               /* SPI2                                        */
  USART1_IRQHandler,             /* USART1                                      */
  USART2_IRQHandler,             /* USART2                                      */
  USART3_IRQHandler,             /* USART3                                      */
  EXTI15_10_IRQHandler,          /* External Line[15:10]s                       */
  RTC_Alarm_IRQHandler,          /* RTC Alarm (A and B) through EXTI Line       */
  0,                             /* Reserved                                    */
  TIM8_BRK_TIM12_IRQHandler,     /* TIM8 Break and TIM12                        */
  TIM8_UP_TIM13_IRQHandler,      /* TIM8 Update and TIM13                       */
  TIM8_TRG_COM_TIM14_IRQHandler, /* TIM8 Trigger and Commutation and TIM14      */
  TIM8_CC_IRQHandler,            /* TIM8 Capture Compare                        */
  DMA1_Stream7_IRQHandler,       /* DMA1 Stream7                                */
  FMC_IRQHandler,                /* FMC                                         */
  SDMMC1_IRQHandler,             /* SDMMC1                                      */
  TIM5_IRQHandler,               /* TIM5                                        */
  SPI3_IRQHandler,               /* SPI3                                        */
  UART4_IRQHandler,              /* UART4                                       */
  UART5_IRQHandler,              /* UART5                                       */
  TIM6_DAC_IRQHandler,           /* TIM6 and DAC1&2 underrun errors             */
  TIM7_IRQHandler,               /* TIM7                                        */
  DMA2_Stream0_IRQHandler,       /* DMA2 Stream 0                               */
  DMA2_Stream1_IRQHandler,       /* DMA2 Stream 1                               */
  DMA2_Stream2_IRQHandler,       /* DMA2 Stream 2                               */
  DMA2_Stream3_IRQHandler,       /* DMA2 Stream 3                               */
  DMA2_Stream4_IRQHandler,       /* DMA2 Stream 4                               */
  ETH_IRQHandler,                /* Ethernet                                    */
  ETH_WKUP_IRQHandler,           /* Ethernet Wakeup through EXTI line           */
  FDCAN_CAL_IRQHandler,          /* FDCAN calibration unit interrupt            */
  0,                             /* Reserved                                    */
  0,                             /* Reserved                                    */
  0,                             /* Reserved                                    */
  0,                             /* Reserved                                    */
  DMA2_Stream5_IRQHandler,       /* DMA2 Stream 5                               */
  DMA2_Stream6_IRQHandler,       /* DMA2 Stream 6                               */
  DMA2_Stream7_IRQHandler,       /* DMA2 Stream 7                               */
  USART6_IRQHandler,             /* USART6                                      */
  I2C3_EV_IRQHandler,            /* I2C3 event                                  */
  I2C3_ER_IRQHandler,            /* I2C3 error                                  */
  OTG_HS_EP1_OUT_IRQHandler,     /* USB OTG HS End Point 1 Out                  */
  OTG_HS_EP1_IN_IRQHandler,      /* USB OTG HS End Point 1 In                   */
  OTG_HS_WKUP_IRQHandler,        /* USB OTG HS Wakeup through EXTI              */
  OTG_HS_IRQHandler,             /* USB OTG HS                                  */
  DCMI_IRQHandler,               /* DCMI                                        */
  CRYP_IRQHandler,               /* Crypto                                      */
  HASH_RNG_IRQHandler,           /* Hash and Rng                                */
  FPU_IRQHandler,                /* FPU                                         */
  UART7_IRQHandler,              /* UART7                                       */
  UART8_IRQHandler,              /* UART8                                       */
  SPI4_IRQHandler,               /* SPI4                                        */
  SPI5_IRQHandler,               /* SPI5                                        */
  SPI6_IRQHandler,               /* SPI6                                        */
  SAI1_IRQHandler,               /* SAI1                                        */
  LTDC_IRQHandler,               /* LTDC                                        */
  LTDC_ER_IRQHandler,            /* LTDC error                                  */
  DMA2D_IRQHandler,              /* DMA2D                                       */
  SAI2_IRQHandler,               /* SAI2                                        */
  QUADSPI_IRQHandler,            /* QUADSPI                                     */
  LPTIM1_IRQHandler,             /* LPTIM1                                      */
  CEC_IRQHandler,                /* HDMI_CEC                                    */
  I2C4_EV_IRQHandler,            /* I2C4 Event                                  */
  I2C4_ER_IRQHandler,            /* I2C4 Error                                  */
  SPDIF_RX_IRQHandler,           /* SPDIF_RX                                    */
  OTG_FS_EP1_OUT_IRQHandler,     /* USB OTG FS End Point 1 Out                  */
  OTG_FS_EP1_IN_IRQHandler,      /* USB OTG FS End Point 1 In                   */
  OTG_FS_WKUP_IRQHandler,        /* USB OTG FS Wakeup through EXTI              */
  OTG_FS_IRQHandler,             /* USB OTG FS                                  */
  DMAMUX1_OVR_IRQHandler,        /* DMAMUX1 Overrun interrupt                   */
  HRTIM1_Master_IRQHandler,      /* HRTIM Master Timer global Interrupt         */
  HRTIM1_TIMA_IRQHandler,        /* HRTIM Timer A global Interrupt              */
  HRTIM1_TIMB_IRQHandler,        /* HRTIM Timer B global Interrupt              */
  HRTIM1_TIMC_IRQHandler,        /* HRTIM Timer C global Interrupt              */
  HRTIM1_TIMD_IRQHandler,        /* HRTIM Timer D global Interrupt              */
  HRTIM1_TIME_IRQHandler,        /* HRTIM Timer E global Interrupt              */
  HRTIM1_FLT_IRQHandler,         /* HRTIM Fault global Interrupt                */
  DFSDM1_FLT0_IRQHandler,        /* DFSDM Filter0 Interrupt                     */
  DFSDM1_FLT1_IRQHandler,        /* DFSDM Filter1 Interrupt                     */
  DFSDM1_FLT2_IRQHandler,        /* DFSDM Filter2 Interrupt                     */
  DFSDM1_FLT3_IRQHandler,        /* DFSDM Filter3 Interrupt                     */
  SAI3_IRQHandler,               /* SAI3 global Interrupt                       */
  SWPMI1_IRQHandler,             /* Serial Wire Interface 1 global interrupt    */
  TIM15_IRQHandler,              /* TIM15 global Interrupt                      */
  TIM16_IRQHandler,              /* TIM16 global Interrupt                      */
  TIM17_IRQHandler,              /* TIM17 global Interrupt                      */
  MDIOS_WKUP_IRQHandler,         /* MDIOS Wakeup  Interrupt                     */
  MDIOS_IRQHandler,              /* MDIOS global Interrupt                      */
  JPEG_IRQHandler,               /* JPEG global Interrupt                       */
  MDMA_IRQHandler,               /* MDMA global Interrupt                       */
  0,                             /* Reserved                                    */
  SDMMC2_IRQHandler,             /* SDMMC2 global Interrupt                     */
  HSEM1_IRQHandler,              /* HSEM1 global Interrupt                      */
  0,                             /* Reserved                                    */
  ADC3_IRQHandler,               /* ADC3 global Interrupt                       */
  DMAMUX2_OVR_IRQHandler,        /* DMAMUX Overrun interrupt                    */
  BDMA_Channel0_IRQHandler,      /* BDMA Channel 0 global Interrupt             */
  BDMA_Channel1_IRQHandler,      /* BDMA Channel 1 global Interrupt             */
  BDMA_Channel2_IRQHandler,      /* BDMA Channel 2 global Interrupt             */
  BDMA_Channel3_IRQHandler,      /* BDMA Channel 3 global Interrupt             */
  BDMA_Channel4_IRQHandler,      /* BDMA Channel 4 global Interrupt             */
  BDMA_Channel5_IRQHandler,      /* BDMA Channel 5 global Interrupt             */
  BDMA_Channel6_IRQHandler,      /* BDMA Channel 6 global Interrupt             */
  BDMA_Channel7_IRQHandler,      /* BDMA Channel 7 global Interrupt             */
  COMP1_IRQHandler,              /* COMP1 global Interrupt                      */
  LPTIM2_IRQHandler,             /* LP TIM2 global interrupt                    */
  LPTIM3_IRQHandler,             /* LP TIM3 global interrupt                    */
  LPTIM4_IRQHandler,             /* LP TIM4 global interrupt                    */
  LPTIM5_IRQHandler,             /* LP TIM5 global interrupt                    */
  LPUART1_IRQHandler,            /* LP UART1 interrupt                          */
  0,                             /* Reserved                                    */
  CRS_IRQHandler,                /* Clock Recovery Global Interrupt             */
  ECC_IRQHandler,                /* ECC diagnostic Global Interrupt             */
  SAI4_IRQHandler,               /* SAI4 global interrupt                       */
  0,                             /* Reserved                                    */
  0,                             /* Reserved                                    */
  WAKEUP_PIN_IRQHandler,         /* Interrupt for all 6 wake-up pins            */
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

inline __attribute__((always_inline)) void init_tables(void)
{
  for (copy_table_t const *e = &__copy_table_start__; e < &__copy_table_end__; ++e) {
    for (uint32_t i = 0u; i < e->wlen; ++i) {
      e->dest[i] = e->src[i];
    }
  }

  for (zero_table_t const *e = &__zero_table_start__; e < &__zero_table_end__; ++e) {
    for (uint32_t i = 0u; i < e->wlen; ++i) {
      e->dest[i] = 0u;
    }
  }
}

/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
__attribute__((__noreturn__)) void Reset_Handler(void)
{
  init_tables();
  SystemInit(); /* CMSIS System Initialization */
  __libc_init_array();

  VTOR = (uint32_t)&__Vectors;

  main();
  while (1) { }
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while (1)
    ;
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
