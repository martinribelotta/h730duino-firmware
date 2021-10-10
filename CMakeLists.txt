cmake_minimum_required(VERSION 3.21)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain-arm_none_eabi.cmake)

project(tst-h730)
add_executable(tst-h730)
enable_language(C CXX ASM)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/utils.cmake)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    -DUSE_HAL_DRIVER
    -DSTM32H730xx
    -DDATA_IN_D2_SRAM
    -DCFG_TUSB_MCU=OPT_MCU_STM32H7
    -DBOARD_DEVICE_RHPORT_NUM=1
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Core/Inc
    Drivers/STM32H7xx_HAL_Driver/Inc
    Drivers/STM32H7xx_HAL_Driver/Inc/Legacy
    Drivers/CMSIS/Device/ST/STM32H7xx/Include
    Drivers/CMSIS/Include
    FATFS/Target
    FATFS/App
    Middlewares/Third_Party/FatFs/src
    LWIP/App
    LWIP/Target
    Middlewares/Third_Party/LwIP/src/include
    Middlewares/Third_Party/LwIP/system
    Drivers/BSP/Components/lan8742
    Middlewares/Third_Party/LwIP/src/include/netif/ppp
    Middlewares/Third_Party/LwIP/src/include/lwip
    Middlewares/Third_Party/LwIP/src/include/lwip/apps
    Middlewares/Third_Party/LwIP/src/include/lwip/priv
    Middlewares/Third_Party/LwIP/src/include/lwip/prot
    Middlewares/Third_Party/LwIP/src/include/netif
    Middlewares/Third_Party/LwIP/src/include/compat/posix
    Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa
    Middlewares/Third_Party/LwIP/src/include/compat/posix/net
    Middlewares/Third_Party/LwIP/src/include/compat/posix/sys
    Middlewares/Third_Party/LwIP/src/include/compat/stdc
    Middlewares/Third_Party/LwIP/system/arch
    app
    microrl
    mpaland-printf
    segger-rtt/RTT
    tinyusb/src
    hisahi-scanf
)
target_add_all_headers(${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE
    Core/Src/main.c
    Core/Src/stm32h7xx_it.c
    Core/Src/stm32h7xx_hal_msp.c
    Core/Src/system_stm32h7xx.c
    Core/Src/usb_descriptors.c
    Core/Src/startup.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_fdcan.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_ospi.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rtc_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_sdmmc.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_delayblock.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_sd_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pcd_ex.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_ll_usb.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_eth_ex.c
    FATFS/App/fatfs.c
    FATFS/Target/bsp_driver_sd.c
    FATFS/Target/sd_diskio.c
    Middlewares/Third_Party/FatFs/src/diskio.c
    Middlewares/Third_Party/FatFs/src/ff.c
    Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
    Middlewares/Third_Party/FatFs/src/option/syscall.c
    Middlewares/Third_Party/FatFs/src/option/ccsbcs.c
    LWIP/App/lwip.c
    LWIP/Target/ethernetif.c
    Drivers/BSP/Components/lan8742/lan8742.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/auth.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ccp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap_ms.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap-md5.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/chap-new.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/demand.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/eap.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/eui64.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/fsm.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ipcp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ipv6cp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/lcp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/magic.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/mppe.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/multilink.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ppp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppapi.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppcrypt.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppoe.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppol2tp.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/pppos.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/upap.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/utils.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/vj.c
    Middlewares/Third_Party/LwIP/src/netif/bridgeif.c
    Middlewares/Third_Party/LwIP/src/netif/bridgeif_fdb.c
    Middlewares/Third_Party/LwIP/src/netif/ethernet.c
    Middlewares/Third_Party/LwIP/src/netif/lowpan6.c
    Middlewares/Third_Party/LwIP/src/netif/lowpan6_ble.c
    Middlewares/Third_Party/LwIP/src/netif/lowpan6_common.c
    Middlewares/Third_Party/LwIP/src/netif/slipif.c
    Middlewares/Third_Party/LwIP/src/netif/zepif.c
    Middlewares/Third_Party/LwIP/src/netif/ppp/ecp.c
    Middlewares/Third_Party/LwIP/src/api/netdb.c
    Middlewares/Third_Party/LwIP/src/api/tcpip.c
    Middlewares/Third_Party/LwIP/src/api/sockets.c
    Middlewares/Third_Party/LwIP/src/api/api_msg.c
    Middlewares/Third_Party/LwIP/src/api/netifapi.c
    Middlewares/Third_Party/LwIP/src/api/api_lib.c
    Middlewares/Third_Party/LwIP/src/api/err.c
    Middlewares/Third_Party/LwIP/src/api/if_api.c
    Middlewares/Third_Party/LwIP/src/api/netbuf.c
    Middlewares/Third_Party/LwIP/src/core/mem.c
    Middlewares/Third_Party/LwIP/src/core/tcp_in.c
    Middlewares/Third_Party/LwIP/src/core/stats.c
    Middlewares/Third_Party/LwIP/src/core/def.c
    Middlewares/Third_Party/LwIP/src/core/inet_chksum.c
    Middlewares/Third_Party/LwIP/src/core/udp.c
    Middlewares/Third_Party/LwIP/src/core/sys.c
    Middlewares/Third_Party/LwIP/src/core/altcp_alloc.c
    Middlewares/Third_Party/LwIP/src/core/dns.c
    Middlewares/Third_Party/LwIP/src/core/netif.c
    Middlewares/Third_Party/LwIP/src/core/timeouts.c
    Middlewares/Third_Party/LwIP/src/core/raw.c
    Middlewares/Third_Party/LwIP/src/core/altcp_tcp.c
    Middlewares/Third_Party/LwIP/src/core/tcp_out.c
    Middlewares/Third_Party/LwIP/src/core/memp.c
    Middlewares/Third_Party/LwIP/src/core/pbuf.c
    Middlewares/Third_Party/LwIP/src/core/altcp.c
    Middlewares/Third_Party/LwIP/src/core/ip.c
    Middlewares/Third_Party/LwIP/src/core/init.c
    Middlewares/Third_Party/LwIP/src/core/tcp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/autoip.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_frag.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/icmp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/dhcp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/ip4_addr.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/etharp.c
    Middlewares/Third_Party/LwIP/src/core/ipv4/igmp.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/dhcp6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/icmp6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/inet6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ethip6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/nd6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_addr.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/mld6.c
    Middlewares/Third_Party/LwIP/src/core/ipv6/ip6_frag.c
    Middlewares/Third_Party/LwIP/src/apps/mqtt/mqtt.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rng.c
    Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rng_ex.c
    app/app.cpp
    app/exec.c
    app/sdcmd.c
    app/cmd_eth.c
    app/sched.c
    app/version.c
    app/hardfault.c
    app/app_utils.c
    app/cmd_utils.c
    app/sched_impl.c
    app/printf_retarget.c
    app/qspi_ffi.c
    microrl/microrl.c
    mpaland-printf/printf.c
    segger-rtt/RTT/SEGGER_RTT_printf.c
    segger-rtt/RTT/SEGGER_RTT.c
    segger-rtt/RTT/SEGGER_RTT_ASM_ARMv7M.s
    segger-rtt/Syscalls/SEGGER_RTT_Syscalls_GCC.c
    tinyusb/src/tusb.c
    tinyusb/src/common/tusb_fifo.c
    tinyusb/src/device/usbd.c
    tinyusb/src/device/usbd_control.c
    tinyusb/src/class/audio/audio_device.c
    tinyusb/src/class/cdc/cdc_device.c
    tinyusb/src/class/dfu/dfu_device.c
    tinyusb/src/class/dfu/dfu_rt_device.c
    tinyusb/src/class/hid/hid_device.c
    tinyusb/src/class/midi/midi_device.c
    tinyusb/src/class/msc/msc_device.c
    tinyusb/src/class/net/net_device.c
    tinyusb/src/class/usbtmc/usbtmc_device.c
    tinyusb/src/class/vendor/vendor_device.c
    tinyusb/src/portable/st/synopsys/dcd_synopsys.c
    hisahi-scanf/scanf.c
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
