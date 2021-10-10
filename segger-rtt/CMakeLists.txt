add_library(segger-rtt INTERFACE)

target_include_directories(segger-rtt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/RTT)
add_all_headers_from(segger-rtt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/RTT)
target_sources(segger-rtt INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/RTT/SEGGER_RTT_printf.c
    ${CMAKE_CURRENT_LIST_DIR}/RTT/SEGGER_RTT.c
    ${CMAKE_CURRENT_LIST_DIR}/RTT/SEGGER_RTT_ASM_ARMv7M.s
    ${CMAKE_CURRENT_LIST_DIR}/Syscalls/SEGGER_RTT_Syscalls_GCC.c
)
