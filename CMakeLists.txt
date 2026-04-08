cmake_minimum_required(VERSION 3.24)

project(vlib_std
        VERSION 1.0.0
        DESCRIPTION "A standard C library"
        LANGUAGES C
)

if(NOT CMAKE_C_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR "This project supports GCC only.")
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(ProjectOptions)
include(CompilerWarnings)
include(Hardening)
include(Macros)

add_subdirectory(src)

if(VLIB_STD_BUILD_TESTS)
    include(CTest)
    #enable_testing()
    add_subdirectory(test)
endif()

if(VLIB_STD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

if(VLIB_STD_ENABLE_INSTALL)
    include(InstallRules)
endif()