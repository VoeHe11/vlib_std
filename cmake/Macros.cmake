function(vlib_std_apply_library_defaults target_name)
    if(NOT TARGET "${target_name}")
        message(FATAL_ERROR "Target '${target_name}' does not exist.")
    endif()

    target_compile_features("${target_name}" PUBLIC c_std_23)

    target_compile_options("${target_name}" PRIVATE
            $<$<COMPILE_LANG_AND_ID:C,GNU>:${VLIB_STD_WARNING_OPTIONS}>
            $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:${VLIB_STD_HARDENING_DEBUG}>
            $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:RelWithDebInfo>>:${VLIB_STD_HARDENING_RELWITHDEBINFO}>
            $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:Release>>:${VLIB_STD_HARDENING_RELEASE}>
            $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:MinSizeRel>>:${VLIB_STD_HARDENING_MINSIZEREL}>
    )
endfunction()

function(vlib_std_apply_test_defaults target_name)
    if(NOT TARGET "${target_name}")
        message(FATAL_ERROR "Target '${target_name}' does not exist.")
    endif()

    target_compile_features("${target_name}" PRIVATE c_std_23)

    target_compile_options("${target_name}" PRIVATE
            $<$<COMPILE_LANG_AND_ID:C,GNU>:${VLIB_STD_WARNING_OPTIONS}>
            $<$<AND:$<COMPILE_LANG_AND_ID:C,GNU>,$<CONFIG:Debug>>:${VLIB_STD_HARDENING_DEBUG}>
    )
endfunction()