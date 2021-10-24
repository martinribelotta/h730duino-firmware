cmake_minimum_required(VERSION 3.21)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain-arm_none_eabi.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(tst-h730)
add_executable(tst-h730)
enable_language(C CXX ASM)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/utils.cmake)

target_compile_definitions(${PROJECT_NAME} PRIVATE -DUSE_HAL_DRIVER -DSTM32H730xx -DDATA_IN_D2_SRAM)

set(VERSION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/app/version.c)
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E touch ${VERSION_FILE})

target_add_src_inc_from(${PROJECT_NAME} PRIVATE Core)
target_add_src_from(${PROJECT_NAME} PRIVATE app)
target_add_src_from(${PROJECT_NAME} PRIVATE microrl)
target_add_src_from(${PROJECT_NAME} PRIVATE mpaland-printf)
target_add_src_from(${PROJECT_NAME} PRIVATE hisahi-scanf)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS CMSIS CMSIS_STM32H7xx)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32H7xx_HAL_Driver stm32h7xx_hal_driver)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/LwIP LwIP)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs FatFS)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tinyusb tinyusb)
target_add_and_link(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/segger-rtt segger-rtt)

target_add_includes_and_headers(${PROJECT_NAME} PRIVATE
    FATFS/Target
    FATFS/App
    LWIP/App
    LWIP/Target
    Drivers/BSP/Components/lan8742
)

target_sources(${PROJECT_NAME} PRIVATE
    FATFS/App/fatfs.c
    FATFS/Target/bsp_driver_sd.c
    FATFS/Target/sd_diskio.c
    LWIP/App/lwip.c
    LWIP/Target/ethernetif.c
    Drivers/BSP/Components/lan8742/lan8742.c
)

set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/STM32H730ZBTx_FLASH.ld)

target_link_options(${PROJECT_NAME} PRIVATE -T${LINKER_SCRIPT})
target_add_disassembler(${PROJECT_NAME} ${LINKER_SCRIPT})
target_add_bin(${PROJECT_NAME})
target_add_hex(${PROJECT_NAME})

list(APPEND openocd_configs "interface/stlink.cfg")
list(APPEND openocd_configs "target/stm32h7x.cfg")
list(APPEND openocd_configs "${CMAKE_CURRENT_SOURCE_DIR}/tools/reset_config.cfg")

list(APPEND flash_commands "init")
list(APPEND flash_commands "reset halt")
list(APPEND flash_commands "program $<TARGET_FILE:${PROJECT_NAME}> verify reset exit")

target_create_openocd_task(${PROJECT_NAME} flash "${openocd_configs}" "${flash_commands}")
