function(vlib_std_apply_library_defaults target_name)
    if(NOT TARGET "${target_name}")
        message(FATAL_ERROR "Target '${target_name}' does not exist.")
    endif()

    target_link_libraries("${target_name}"
            PUBLIC
            vlib_std_project_warnings
            vlib_std_project_hardening
    )

    set_target_properties("${target_name}" PROPERTIES
            POSITION_INDEPENDENT_CODE ON
    )
endfunction()

function(vlib_std_apply_test_defaults target_name)
    if(NOT TARGET "${target_name}")
        message(FATAL_ERROR "Target '${target_name}' does not exist.")
    endif()

    target_link_libraries("${target_name}"
            PRIVATE
            vlib_std_project_warnings
    )

    if(VLIB_STD_ENABLE_ASAN)
        target_compile_options("${target_name}" PRIVATE
                $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:
                -fsanitize=address,undefined
                -fsanitize-address-use-after-scope
                >
        )
        target_link_options("${target_name}" PRIVATE
                $<$<AND:$<LINK_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:
                -fsanitize=address,undefined
                >
        )
    endif()

    if(VLIB_STD_ENABLE_TSAN)
        target_compile_options("${target_name}" PRIVATE
                $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:
                -fsanitize=thread
                >
        )
        target_link_options("${target_name}" PRIVATE
                $<$<AND:$<LINK_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:
                -fsanitize=thread
                >
        )
    endif()
endfunction()