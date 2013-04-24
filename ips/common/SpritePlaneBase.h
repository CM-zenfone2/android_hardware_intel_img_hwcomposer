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
#ifndef SPRITE_PLANE_BASE_H
#define SPRITE_PLANE_BASE_H

#include <utils/KeyedVector.h>
#include <hal_public.h>
#include <BufferCache.h>
#include <DisplayPlane.h>

#include <displayclass_interface.h>

namespace android {
namespace intel {

class SpritePlaneBase : public DisplayPlane {
public:
    SpritePlaneBase(int index, int disp);
    virtual ~SpritePlaneBase();
public:
    // hardware operations
    virtual bool reset();
    virtual bool flip();
    virtual bool enable();
    virtual bool disable();

    virtual void setZOrderConfig(ZOrderConfig& config);
    // display device
    virtual void* getContext() const = 0;
protected:
    virtual bool setDataBuffer(BufferMapper& mapper) = 0;
    virtual void checkPosition(int& x, int& y, int& w, int& h);
protected:
    bool mForceBottom;
};

} // namespace intel
} // namespace android

#endif /* SPRITE_PLANE_BASE_H */

