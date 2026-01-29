// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#pragma once

#include <filesystem>
#include <vector>
#include "Export.h"

namespace vsg::plugin
{
    VSGPLUGIN_DECLSPEC std::vector<std::filesystem::path> pluginPaths();
}
