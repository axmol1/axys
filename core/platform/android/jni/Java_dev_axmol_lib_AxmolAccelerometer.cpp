/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 Copyright (c) 2019-present Axmol Engine contributors (see AUTHORS.md).

 https://axmol.dev/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include <jni.h>
#include "base/Director.h"
#include "base/EventDispatcher.h"
#include "base/EventAcceleration.h"

#define TG3_GRAVITY_EARTH (9.80665f)

using namespace ax;

extern "C" {
JNIEXPORT void JNICALL Java_dev_axmol_lib_AxmolAccelerometer_onSensorChanged(JNIEnv*,
                                                                                   jclass,
                                                                                   jfloat x,
                                                                                   jfloat y,
                                                                                   jfloat z,
                                                                                   jlong timeStamp)
{
    Acceleration a;
    a.x         = -((double)x / TG3_GRAVITY_EARTH);
    a.y         = -((double)y / TG3_GRAVITY_EARTH);
    a.z         = -((double)z / TG3_GRAVITY_EARTH);
    a.timestamp = (double)timeStamp / 1e9;

    EventAcceleration event(a);
    Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}
}
