// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#include <vsg/plugin/PluginLoader.h>
#include <vsg/io/Options.h>

int main()
{
    auto options = vsg::Options::create();
    vsg::plugin::loadPlugins(*options);
    return 0;
}
