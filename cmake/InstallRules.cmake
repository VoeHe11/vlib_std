install(
        TARGETS vlib_std
        EXPORT vlib_stdTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        FILE_SET public_headers DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
        EXPORT vlib_stdTargets
        FILE vlib_stdTargets.cmake
        NAMESPACE vlib_std::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vlib_std
)

configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/vlib_stdConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vlib_std
)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/vlib_stdConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
)

install(
        FILES
        ${CMAKE_CURRENT_BINARY_DIR}/Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/vlib_stdConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vlib_std
)