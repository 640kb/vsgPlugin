# SPDX-FileCopyrightText: 2026 Ralf Habacker
#
# SPDX-License-Identifier: MIT

include(GNUInstallDirs)

include(CMakePackageConfigHelpers)

function(vsgplugin_install_core)
    set(options)
    set(oneValueArgs TARGET VERSION)
    set(multiValueArgs)

    cmake_parse_arguments(VSGPLUGIN
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    if(NOT VSGPLUGIN_TARGET)
        message(FATAL_ERROR "vsgplugin_install_core(): TARGET is required")
    endif()

    if(NOT VSGPLUGIN_VERSION)
        message(FATAL_ERROR "vsgplugin_install_core(): VERSION is required")
    endif()

    # ---- install library + headers ----

    install(TARGETS ${VSGPLUGIN_TARGET}
        EXPORT vsgPluginTargets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # ---- export targets ----

    install(EXPORT vsgPluginTargets
        NAMESPACE vsg::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vsgPlugin
    )

    # ---- generate Config + Version files ----

    configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/vsgPluginConfig.cmake.in
        ${PROJECT_BINARY_DIR}/vsgPluginConfig.cmake
        INSTALL_DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/vsgPlugin
    )

    write_basic_package_version_file(
        ${PROJECT_BINARY_DIR}/vsgPluginConfigVersion.cmake
        VERSION ${VSGPLUGIN_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(
        FILES
            ${PROJECT_BINARY_DIR}/vsgPluginConfig.cmake
            ${PROJECT_BINARY_DIR}/vsgPluginConfigVersion.cmake
        DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/vsgPlugin
    )
endfunction()
