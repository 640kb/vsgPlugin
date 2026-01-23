// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#include "MyReaderWriter.h"

#include <vsg/core/Object.h>
#include <vsg/io/Options.h>

#include <fstream>
#include <iostream>

namespace myformat
{

bool MyReaderWriter::getFeatures(Features& features) const
{
    // Advertise that we can READ files with extension ".myfmt"
    features.extensionFeatureMap["myfmt"] =
        vsg::ReaderWriter::READ_FILENAME;

    // Optional examples:
    // features.protocolFeatureMap["myproto"] = READ_FILENAME;
    // features.optionNameTypeMap["myOption"] = "bool";

    return true;
}

vsg::ref_ptr<vsg::Object> MyReaderWriter::read(
    const vsg::Path& filename,
    vsg::ref_ptr<const vsg::Options>) const
{
    std::ifstream in(filename, std::ios::binary);
    if (!in) return {};

    std::cout << "[MyReaderWriter] Reading file: " << filename << "\n";

    return vsg::Object::create(); // placeholder
}

bool MyReaderWriter::write(
    const vsg::Object*,
    const vsg::Path& filename,
    vsg::ref_ptr<const vsg::Options>) const
{
    std::ofstream out(filename, std::ios::binary);
    if (!out) return false;

    // TODO: serialize object

    return true;
}

} // namespace myformat
