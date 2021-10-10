add_library(tinyusb INTERFACE)

target_include_directories(tinyusb INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src)
target_compile_definitions(tinyusb INTERFACE
    -DCFG_TUSB_MCU=OPT_MCU_STM32H7
    -DBOARD_DEVICE_RHPORT_NUM=1
)
set(ALL_SRC
    ${CMAKE_CURRENT_LIST_DIR}/src/tusb.c
    ${CMAKE_CURRENT_LIST_DIR}/src/common/tusb_fifo.c
    ${CMAKE_CURRENT_LIST_DIR}/src/device/usbd.c
    ${CMAKE_CURRENT_LIST_DIR}/src/device/usbd_control.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/audio/audio_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/cdc/cdc_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/dfu/dfu_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/dfu/dfu_rt_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/hid/hid_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/midi/midi_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/msc/msc_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/net/net_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/usbtmc/usbtmc_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/class/vendor/vendor_device.c
    ${CMAKE_CURRENT_LIST_DIR}/src/portable/st/synopsys/dcd_synopsys.c
)
file(GLOB_RECURSE ALL_H LIST_DIRECTORIES false ${CMAKE_CURRENT_LIST_DIR}/src/*.h)
target_sources(tinyusb INTERFACE "${ALL_SRC}" "${ALL_H}")
