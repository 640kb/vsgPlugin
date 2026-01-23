// SPDX-FileCopyrightText: 2026 Ralf Habacker
//
// SPDX-License-Identifier: MIT

#pragma once

//#include "myformat_export.h"
#define MYFORMAT_PLUGIN_EXPORT

#include <vsg/io/ReaderWriter.h>

namespace myformat
{

class MYFORMAT_PLUGIN_EXPORT MyReaderWriter : public vsg::Inherit<vsg::ReaderWriter, MyReaderWriter>
{
public:
    MyReaderWriter() = default;

    // Advertise supported features (extensions, protocols, options)
    bool getFeatures(Features& features) const override;

    // Read from file
    vsg::ref_ptr<vsg::Object> read(
        const vsg::Path& filename,
        vsg::ref_ptr<const vsg::Options> options = {}) const override;

    // Optional: write support
    bool write(
        const vsg::Object* object,
        const vsg::Path& filename,
        vsg::ref_ptr<const vsg::Options> options = {}) const override;
};

} // namespace myformat
