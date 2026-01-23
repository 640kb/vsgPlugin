cmake_minimum_required(VERSION 3.16)
project(vsgPluginPackageTest LANGUAGES CXX)

find_package(vsg CONFIG REQUIRED)
find_package(vsgPlugin CONFIG REQUIRED)

add_executable(vsgplugin_package_test
    main.cpp
)

target_link_libraries(vsgplugin_package_test
    PRIVATE
        vsg::vsg
        vsg::vsgPlugin
)
