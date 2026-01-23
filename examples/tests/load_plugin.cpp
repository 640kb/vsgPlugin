#include <vsg/plugin/PluginLoader.h>
#include <vsg/io/Options.h>
#include <vsg/io/read.h>

int main(int argc, char** argv)
{
    auto options = vsg::Options::create();

    // load all plugins
    vsg::plugin::loadPlugins(*options);

    // Try to load something that requires a plugin
    auto node = vsg::read_cast<vsg::Node>("dummy.myformat", options);

    // We don't care if loading fails – only that plugins load cleanly
    return 0;
}
