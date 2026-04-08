set(VLIB_STD_WARNING_OPTIONS
        -Wall
        -Wextra
        -Wpedantic
        -Wformat=2
        -Wformat-overflow=2
        -Wformat-truncation=2
        -Wstringop-overflow=4
        -Warray-bounds=2
        -Wconversion
        -Wsign-conversion
        -Wcast-qual
        -Wcast-align=strict
        -Wshadow
        -Wundef
        -Wnull-dereference
        -Wdouble-promotion
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wswitch-enum
        -Wstrict-prototypes
        -Wmissing-prototypes
        -Wwrite-strings
        -Wvla
        -Walloca
        -Walloc-zero
        -Wfree-nonheap-object
        -Wstack-protector
        -fstrict-flex-arrays=3
)

if(VLIB_STD_WARNINGS_AS_ERRORS)
    list(APPEND VLIB_STD_WARNING_OPTIONS -Werror)
endif()

if(VLIB_STD_ENABLE_ANALYZER)
    list(APPEND VLIB_STD_WARNING_OPTIONS -fanalyzer)
endif()