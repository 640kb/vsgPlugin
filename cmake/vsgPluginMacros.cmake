# SPDX-FileCopyrightText: 2026 Ralf Habacker
#
# SPDX-License-Identifier: MIT

function(vsgplugin_setup_plugin)
    set(options)
    set(oneValueArgs TARGET PLUGIN_NAME)
    set(multiValueArgs)

    cmake_parse_arguments(VSGPLUGIN
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    if(NOT VSGPLUGIN_TARGET)
        message(FATAL_ERROR "vsgplugin_setup_plugin(): TARGET is required")
    endif()

    if(NOT VSGPLUGIN_PLUGIN_NAME)
        message(FATAL_ERROR "vsgplugin_setup_plugin(): PLUGIN_NAME is required")
    endif()

    set(VSG_PLUGIN_ABI_VERSION ${vsg_VERSION_MAJOR})

    if(WIN32)
        set(_plugin_dir
            ${CMAKE_INSTALL_BINDIR}/vsgPlugins-${VSG_PLUGIN_ABI_VERSION}
        )
    else()
        set(_plugin_dir
            ${CMAKE_INSTALL_LIBDIR}/vsgPlugins-${VSG_PLUGIN_ABI_VERSION}
        )
    endif()

    set_target_properties(${VSGPLUGIN_TARGET} PROPERTIES
        OUTPUT_NAME "vsgPlugin-${VSGPLUGIN_PLUGIN_NAME}"
    )

    install(TARGETS ${VSGPLUGIN_TARGET}
        RUNTIME DESTINATION ${_plugin_dir}
        LIBRARY DESTINATION ${_plugin_dir}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
endfunction()
