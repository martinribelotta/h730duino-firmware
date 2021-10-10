function(target_add_src_from tgt visibility dir)
    file(GLOB SRC ${dir}/*.c ${dir}/*.cpp ${dir}/*.h ${dir}/*.s)
    target_sources(${tgt} ${visibility} ${SRC})
    target_include_directories(${tgt} ${visibility} ${dir} ${dir}/Inc ${dir}/Include)
endfunction()

function(target_add_src_inc_from tgt visibility base)
    file(GLOB SRC ${base}/Src/*.c ${base}/Src/*.cpp ${base}/Inc/*.h ${base}/Src/*.s)
    target_sources(${tgt} ${visibility} ${SRC})
    target_include_directories(${tgt} ${visibility} ${base}/Inc ${base}/Include)
endfunction()

function(extract_sections ldfile sectionlist)
    set(section_list)
    file(READ ${ldfile} content)
    string(REGEX MATCHALL "([\.][\.a-zA-Z0-9_]+)[ \t\r\n]*\:" sections ${content})
    foreach(I ${sections})
        string(REGEX MATCH "([\.][\.a-zA-Z0-9_]+)[ \t\r\n]*\:" E ${I})
        list(APPEND section_list ${CMAKE_MATCH_1})
    endforeach()
    set(${sectionlist} ${section_list} PARENT_SCOPE)
endfunction()

function(target_add_and_link tgt subdir)
    add_subdirectory(${subdir})
    target_link_libraries(${tgt} ${ARGN})
endfunction()

function(target_add_disassembler tgt ldscript)
    extract_sections(${ldscript} sections)
    list(TRANSFORM sections PREPEND "-j")
    add_custom_command(TARGET ${tgt} POST_BUILD
        COMMAND ${CROSS_OBJDUMP} "-dSx" $<TARGET_FILE:${tgt}> > $<TARGET_FILE:${tgt}>.lst
        COMMENT "Generating disassembler file")
endfunction()

function(target_add_bin tgt)
    add_custom_command(TARGET ${tgt} POST_BUILD
        COMMAND ${CROSS_OBJCOPY} "-Obinary" $<TARGET_FILE:${tgt}> $<TARGET_FILE:${tgt}>.bin
        COMMENT "Generating bin file")
endfunction()

function(target_add_hex tgt)
    add_custom_command(TARGET ${tgt} POST_BUILD
        COMMAND ${CROSS_OBJCOPY} "-Oihex" $<TARGET_FILE:${tgt}> $<TARGET_FILE:${tgt}>.hex
        COMMENT "Generating hex file")
endfunction()

function(add_all_headers_from tgt iface P)
    foreach(d ${P})
        file(GLOB H LIST_DIRECTORIES false ${d}/*.h)
        target_sources(${tgt} ${iface} ${H})
    endforeach()
endfunction()

function(target_add_all_headers tgt)
    get_target_property(P ${tgt} INCLUDE_DIRECTORIES)
    add_all_headers_from(${tgt} PRIVATE ${P})
endfunction()

function(target_add_includes_and_headers tgt visibility)
    target_include_directories(${tgt} ${visibility} ${ARGN})
    add_all_headers_from(${tgt} ${visibility} ${ARGN})
endfunction()

function(target_create_openocd_task tgt tgt_name cfg cmd)
    list(TRANSFORM cfg PREPEND "-f")
    list(TRANSFORM cmd PREPEND "-c")
    find_program(OPENOCD_CMD openocd
        PATHS /opt/openocd/bin/ /usr/bin/ /usr/local/bin /opt/xpack-openocd-0.11.0-1/bin $ENV{OPENOCD_PATH}
        REQUIRED NO_CACHE)

    add_custom_target(${tgt_name}-${tgt}
        COMMAND ${OPENOCD_CMD} ${cfg} ${cmd}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${tgt}
        COMMENT "Running openocd ${tgt_name}"
        USES_TERMINAL)
endfunction()
