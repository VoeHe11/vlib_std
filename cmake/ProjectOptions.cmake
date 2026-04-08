option(VLIB_STD_WARNINGS_AS_ERRORS "Treat warnings as errors" ON)
option(VLIB_STD_ENABLE_ANALYZER "Enable GCC static analyzer" ON)
option(VLIB_STD_ENABLE_HARDENING "Enable GCC hardening profile" ON)
option(VLIB_STD_ENABLE_PIC "Build targets with PIC" ON)

option(VLIB_STD_BUILD_TESTS "Build tests" ON)
option(VLIB_STD_BUILD_EXAMPLES "Build examples" OFF)
option(VLIB_STD_ENABLE_INSTALL "Enable install/export rules" ON)

option(VLIB_STD_ENABLE_ASAN "Enable AddressSanitizer + UBSan for test executables in Debug" ON)
option(VLIB_STD_ENABLE_TSAN "Enable ThreadSanitizer for test executables in Debug" OFF)

if(VLIB_STD_ENABLE_ASAN AND VLIB_STD_ENABLE_TSAN)
    message(FATAL_ERROR "VLIB_STD_ENABLE_ASAN and VLIB_STD_ENABLE_TSAN must not both be ON.")
endif()

if(VLIB_STD_ENABLE_PIC)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()