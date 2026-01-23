#include <vsg/plugin/PluginLoader.h>
#include <vsg/plugin/PluginPaths.h>

#include <vsg/core/Version.h>
#include <vsg/io/ReaderWriter.h>

#include <filesystem>
#include <iostream>

#if defined(_WIN32)
    #include <windows.h>
#else
    #include <dlfcn.h>
#endif

namespace fs = std::filesystem;

namespace vsg::plugin
{

using RegisterRWFunc = void (*)(vsg::Options&);

static void loadPluginLibrary(const fs::path& libraryPath, vsg::Options& options)
{
#if defined(_WIN32)

    HMODULE handle = LoadLibraryW(libraryPath.wstring().c_str());
    if (!handle)
    {
        std::cerr << "vsgPlugin: failed to load " << libraryPath << "\n";
        return;
    }

    auto func = reinterpret_cast<RegisterRWFunc>(
        GetProcAddress(handle, "vsgRegisterReaderWriters")
    );

#else

    void* handle = dlopen(libraryPath.c_str(), RTLD_NOW | RTLD_LOCAL);
    if (!handle)
    {
        std::cerr << "vsgPlugin: failed to load " << libraryPath
                  << " : " << dlerror() << "\n";
        return;
    }

    auto func = reinterpret_cast<RegisterRWFunc>(
        dlsym(handle, "vsgRegisterReaderWriters")
    );

#endif

    if (!func)
    {
        std::cerr << "vsgPlugin: symbol vsgRegisterReaderWriters not found in "
                  << libraryPath << "\n";
        return;
    }

    // Register ReaderWriters into options
    func(options);
}

void loadPlugins(vsg::Options& options)
{
    const auto paths = pluginPaths();

    for (const auto& dir : paths)
    {
        if (!fs::exists(dir) || !fs::is_directory(dir))
            continue;

        for (const auto& entry : fs::directory_iterator(dir))
        {
            if (!entry.is_regular_file())
                continue;

            const auto& path = entry.path();

#if defined(_WIN32)
            if (path.extension() != ".dll")
                continue;
#elif defined(__APPLE__)
            if (path.extension() != ".dylib")
                continue;
#else
            if (path.extension() != ".so")
                continue;
#endif

            loadPluginLibrary(path, options);
        }
    }
}

} // namespace vsg::plugin
