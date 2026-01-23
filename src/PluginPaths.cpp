
#include "vsgPluginConfig.h"

#include <vsg/plugin/PluginPaths.h>
#include <vsg/core/Version.h>
#include <cstdlib>

namespace fs = std::filesystem;

namespace vsg::plugin
{

std::vector<fs::path> pluginPaths()
{
    std::vector<fs::path> paths;

    // 1. Environment override
    if (const char* env = std::getenv("VSG_PLUGIN_PATH"))
    {
        paths.emplace_back(env);
    }

    // 2. Install-time default
#if defined(_WIN32)
    paths.emplace_back(
        fs::path(VSGPLUGIN_INSTALL_BINDIR) /
        ("vsgPlugins-" + std::to_string(VSGPLUGIN_ABI_VERSION))
    );
#else
    paths.emplace_back(
        fs::path(VSGPLUGIN_INSTALL_LIBDIR) /
        ("vsgPlugins-" + std::to_string(VSGPLUGIN_ABI_VERSION))
    );
#endif

    return paths;
}

} // namespace vsg::plugin
