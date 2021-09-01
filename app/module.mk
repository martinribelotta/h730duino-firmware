APP_BASE := $(notdir $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST))))))

C_SOURCES += $(wildcard $(APP_BASE)/*.c)

C_INCLUDES += -I$(APP_BASE)

CXX_SOURCES += $(wildcard $(APP_BASE)/*.cpp)
