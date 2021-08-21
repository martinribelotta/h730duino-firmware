TINYUSB_BASE = tinyusb-0.10.1

C_SOURCES += \
	$(TINYUSB_BASE)/src/tusb.c \
	$(TINYUSB_BASE)/src/common/tusb_fifo.c \
	$(TINYUSB_BASE)/src/device/usbd.c \
	$(TINYUSB_BASE)/src/device/usbd_control.c \
	$(TINYUSB_BASE)/src/class/audio/audio_device.c \
	$(TINYUSB_BASE)/src/class/cdc/cdc_device.c \
	$(TINYUSB_BASE)/src/class/dfu/dfu_device.c \
	$(TINYUSB_BASE)/src/class/dfu/dfu_rt_device.c \
	$(TINYUSB_BASE)/src/class/hid/hid_device.c \
	$(TINYUSB_BASE)/src/class/midi/midi_device.c \
	$(TINYUSB_BASE)/src/class/msc/msc_device.c \
	$(TINYUSB_BASE)/src/class/net/net_device.c \
	$(TINYUSB_BASE)/src/class/usbtmc/usbtmc_device.c \
	$(TINYUSB_BASE)/src/class/vendor/vendor_device.c \
	$(TINYUSB_BASE)/src/portable/st/synopsys/dcd_synopsys.c \
	Core/Src/usb_descriptors.c

C_INCLUDES += -I$(TINYUSB_BASE)/src

C_DEFS += \
  -DCFG_TUSB_MCU=OPT_MCU_STM32H7 \
  -DBOARD_DEVICE_RHPORT_NUM=1
