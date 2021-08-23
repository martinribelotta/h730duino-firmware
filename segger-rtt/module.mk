SEGGER_BASE := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

C_SOURCES +=  \
	$(SEGGER_BASE)/RTT/SEGGER_RTT_printf.c \
	$(SEGGER_BASE)/RTT/SEGGER_RTT.c \
	$(SEGGER_BASE)/Syscalls/SEGGER_RTT_Syscalls_GCC.c

ASM_SOURCES += $(SEGGER_BASE)/RTT/SEGGER_RTT_ASM_ARMv7M.s

C_INCLUDES += -I$(SEGGER_BASE)/RTT
