/*
 * Copyright © 2012 Intel Corporation
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * Authors:
 *    Jackie Li <yaodong.li@intel.com>
 *
 */
#include <HwcTrace.h>
#include <DrmConfig.h>
#include <Drm.h>

namespace android {
namespace intel {

const char* DrmConfig::getDrmPath()
{
    return "/dev/card0";
}

uint32_t DrmConfig::getDrmConnector(int32_t output)
{
    if (output == Drm::OUTPUT_PRIMARY)
        return DRM_MODE_CONNECTOR_MIPI;
    else if (output == Drm::OUTPUT_EXTERNAL)
        return DRM_MODE_CONNECTOR_DVID;

    return DRM_MODE_CONNECTOR_Unknown;
}

const char* DrmConfig::getHotplugEnvelope()
{
    return "change@/devices/pci0000:00/0000:00:02.0/drm/card0";
}

const char* DrmConfig::getHotplugString()
{
    return "HOTPLUG=1";
}

} // namespace intel
} // namespace android
