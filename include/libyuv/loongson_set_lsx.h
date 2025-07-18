/*
 *  Copyright 2025 The LibYuv Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS. All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef LSX_LASX_PUSHED
#define LSX_LASX_PUSHED
#else
#error "loongson_set_l{a,}sx.h ... loongson_unset_target.h shouldn't nest"
#endif

#ifndef __loongarch_sx
#define LSX_PUSHED
#ifdef __clang__
#pragma clang attribute push(__attribute__((target("lsx"))), apply_to=function)
#define __loongarch_sx
#elif defined(__GNUC__) && __GNUC__ >= 15
#pragma GCC push_options
#pragma GCC target "lsx"
#else
#error "LSX is requested but we cannot tell the compiler to enable it"
#endif // __clang__
#endif // __loongarch_sx
