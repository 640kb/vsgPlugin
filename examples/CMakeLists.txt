option(VSGPLUGIN_BUILD_EXAMPLES "Build example plugins" ON)

if(VSGPLUGIN_BUILD_EXAMPLES)
    add_subdirectory(myformat)
endif()

option(VSGPLUGIN_BUILD_TESTS "Build tests" ON)

if(VSGPLUGIN_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
