// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#pragma once

#include <vsg/io/Options.h>

namespace vsg::plugin
{
    /**
     * Load all plugins found in the plugin search paths and register
     * their ReaderWriters into the provided Options object.
     */
    void loadPlugins(vsg::Options& options);
}
