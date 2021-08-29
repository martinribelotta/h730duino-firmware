SCANF_BASE := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

C_SOURCES += $(SCANF_BASE)/scanf.c

C_INCLUDES += -I$(SCANF_BASE)
