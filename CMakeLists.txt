# SPDX-FileCopyrightText: 2026 Ralf Habacker
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.16)
project(vsgPlugin VERSION 1.0.0 LANGUAGES CXX)

find_package(vsg REQUIRED)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(vsgPluginInstall)

configure_file(
    cmake/vsgPluginConfig.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/vsgPluginConfig.h
    @ONLY
)

add_library(vsgPlugin SHARED
    ${CMAKE_CURRENT_BINARY_DIR}/vsgPluginConfig.h
    include/vsg/plugin/PluginLoader.h
    include/vsg/plugin/PluginPaths.h
    src/PluginLoader.cpp
    src/PluginPaths.cpp
)

target_link_libraries(vsgPlugin
    PUBLIC vsg::vsg
)

target_include_directories(vsgPlugin
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(vsgPlugin PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    VERSION ${PROJECT_VERSION}
    SOVERSION ${vsg_VERSION_MAJOR}
)

add_library(vsg::vsgPlugin ALIAS vsgPlugin)

vsgplugin_install_core(
    TARGET vsgPlugin
    VERSION ${PROJECT_VERSION}
)

install(
    FILES
        ${PROJECT_SOURCE_DIR}/cmake/vsgPluginMacros.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/vsgPlugin
)

enable_testing()

add_subdirectory(examples)

option(VSGPLUGIN_ENABLE_PACKAGE_TEST
       "Enable vsgPlugin package consumer test" OFF)

if(VSGPLUGIN_ENABLE_PACKAGE_TEST)
    set(TEMP_INSTALL_DIR ${CMAKE_BINARY_DIR}/_pkgtest)

    add_test(
        NAME vsgplugin-install-clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${TEMP_INSTALL_DIR}
    )

    add_test(
        NAME vsgplugin-install
        COMMAND ${CMAKE_COMMAND}
                --build ${CMAKE_BINARY_DIR}
                --target install
    )

    set_property(TEST vsgplugin-install
        APPEND PROPERTY ENVIRONMENT DESTDIR=${TEMP_INSTALL_DIR}
        APPEND PROPERTY DEPENDS vsgplugin-install-clean
    )

    add_test(
        NAME vsgplugin-build-consumer
        COMMAND ${CMAKE_CTEST_COMMAND}
            --build-and-test
            ${CMAKE_CURRENT_SOURCE_DIR}/cmake/plugin-package
            ${CMAKE_CURRENT_BINARY_DIR}/cmake/plugin-package
            --build-generator ${CMAKE_GENERATOR}
            --build-makeprogram ${CMAKE_MAKE_PROGRAM}
            --build-options
                -DvsgPlugin_DIR=${TEMP_INSTALL_DIR}${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/cmake/vsgPlugin
                -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    )

    set_property(TEST vsgplugin-build-consumer
        APPEND PROPERTY DEPENDS
            vsgplugin-install-clean
            vsgplugin-install
    )
endif()
