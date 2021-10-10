add_library(stm32h7xx_hal_driver INTERFACE)

target_include_directories(stm32h7xx_hal_driver INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Inc
    ${CMAKE_CURRENT_LIST_DIR}/Inc/Legacy
)

file(GLOB ALL_H LIST_DIRECTORIES false
    ${CMAKE_CURRENT_LIST_DIR}/Inc/*.h
    ${CMAKE_CURRENT_LIST_DIR}/Inc/Legacy/*.h
)
target_sources(stm32h7xx_hal_driver INTERFACE "${ALL_H}")
target_sources(stm32h7xx_hal_driver INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_cortex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rcc.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rcc_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_flash.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_flash_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_gpio.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_hsem.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_dma.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_dma_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_mdma.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_pwr.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_pwr_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_i2c.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_i2c_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_exti.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_fdcan.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_ospi.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rtc.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rtc_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_ll_sdmmc.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_ll_delayblock.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_sd.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_sd_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_spi.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_spi_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_tim.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_tim_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_uart.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_uart_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_pcd.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_pcd_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_ll_usb.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_eth.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_eth_ex.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rng.c
    ${CMAKE_CURRENT_LIST_DIR}/Src/stm32h7xx_hal_rng_ex.c
)
