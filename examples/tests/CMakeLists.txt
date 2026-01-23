add_executable(vsgplugin_load_test
    load_plugin.cpp
)

target_link_libraries(vsgplugin_load_test
    PRIVATE
        vsg::vsg
        vsg::vsgPlugin
)

add_test(
    NAME vsgplugin.load
    COMMAND vsgplugin_load_test
)

# Make sure plugins built in-tree are discoverable
set_tests_properties(vsgplugin.load PROPERTIES
    ENVIRONMENT "VSG_PLUGIN_PATH=$<TARGET_FILE_DIR:vsg_myformat>"
)
