// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#pragma once

#include <filesystem>
#include <vector>

namespace vsg::plugin
{
    std::vector<std::filesystem::path> pluginPaths();
}
