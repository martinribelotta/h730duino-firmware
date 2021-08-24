MICRORL_BASE := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

C_SOURCES += $(MICRORL_BASE)/microrl.c

C_INCLUDES += -I$(MICRORL_BASE)
