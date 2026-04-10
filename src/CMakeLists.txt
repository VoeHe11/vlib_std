add_library(vlib_std STATIC
        char/vlib_isalpha.c
        char/vlib_isdigit.c
        char/vlib_isalnum.c
        char/vlib_isascii.c
        char/vlib_isprint.c
        char/vlib_isspace.c
        char/vlib_isupper.c
        char/vlib_islower.c
        char/vlib_toupper.c
)

add_library(vlib_std::vlib_std ALIAS vlib_std)

target_sources(vlib_std
        PUBLIC
        FILE_SET public_headers
        TYPE HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../include
        FILES ${CMAKE_CURRENT_SOURCE_DIR}/../include/vlib_std.h
)

target_include_directories(vlib_std
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal
)

set_target_properties(vlib_std PROPERTIES
        OUTPUT_NAME "vlib_std"
        EXPORT_NAME "vlib_std"
)

vlib_std_apply_library_defaults(vlib_std)