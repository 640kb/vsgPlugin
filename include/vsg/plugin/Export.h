#pragma once

#if (defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__))
#    if defined(vsgPlugin_EXPORTS)
#        define VSGPLUGIN_DECLSPEC __declspec(dllexport)
#    elif defined(VSGPLUGIN_SHARED_LIBRARY)
#        define VSGPLUGIN_DECLSPEC __declspec(dllimport)
#    else
#        define VSGPLUGIN_DECLSPEC
#    endif
#else
#    define VSGPLUGIN_DECLSPEC
#endif
