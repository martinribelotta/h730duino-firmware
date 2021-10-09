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

function(target_add_all_headers tgt)
    get_target_property(P ${tgt} INCLUDE_DIRECTORIES)
    foreach(d ${P})
        file(GLOB H LIST_DIRECTORIES false ${d}/*.h)
        target_sources(${tgt} PRIVATE ${H})
    endforeach()
endfunction()
