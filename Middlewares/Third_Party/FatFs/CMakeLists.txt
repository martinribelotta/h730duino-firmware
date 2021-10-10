add_library(FatFS INTERFACE)

set(INC_PATH ${CMAKE_CURRENT_LIST_DIR}/src)
add_all_headers_from(FatFS INTERFACE "${INC_PATH}")
target_include_directories(FatFS INTERFACE "${INC_PATH}")

target_sources(FatFS INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/diskio.c
    ${CMAKE_CURRENT_LIST_DIR}/src/ff.c
    ${CMAKE_CURRENT_LIST_DIR}/src/ff_gen_drv.c
    ${CMAKE_CURRENT_LIST_DIR}/src/option/syscall.c
    ${CMAKE_CURRENT_LIST_DIR}/src/option/ccsbcs.c
)
