include(vsgPluginMacros)

add_library(vsg_myformat SHARED
    MyReaderWriter.cpp
    MyReaderWriterPlugin.cpp
)

target_link_libraries(vsg_myformat
    PRIVATE vsg::vsg
)

vsgplugin_setup_plugin(
    TARGET vsg_myformat
    PLUGIN_NAME myformat
)
