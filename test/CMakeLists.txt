function(vlib_add_unit_test target_name test_name)
    set(_vlib_tests_root_dir "${CMAKE_CURRENT_FUNCTION_LIST_DIR}")

    add_executable(${target_name}
            ${ARGN}
            ${_vlib_tests_root_dir}/helpers/test_assert.c
    )

    target_include_directories(${target_name}
            PRIVATE
            ${_vlib_tests_root_dir}
    )

    target_link_libraries(${target_name}
            PRIVATE
            vlib_std
    )

    add_test(
            NAME ${test_name}
            COMMAND $<TARGET_FILE:${target_name}>
    )
endfunction()

add_subdirectory(char)
#add_subdirectory(string)