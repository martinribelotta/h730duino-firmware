PRINTF_BASE := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

C_SOURCES += $(PRINTF_BASE)/printf.c

C_INCLUDES += -I$(PRINTF_BASE)
