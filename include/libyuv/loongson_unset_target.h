/*
 *  Copyright 2025 The LibYuv Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS. All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifdef __loongarch__

#if defined(LSX_PUSHED) || defined(LASX_PUSHED)
#ifdef __clang__
#pragma clang attribute pop
#ifdef LSX_PUSHED
#undef __loongarch_sx
#else
#undef __loongarch_asx
#endif // LSX_PUSHED
#else
#pragma GCC pop_options
#endif // __clang__

#undef LSX_PUSHED
#undef LASX_PUSHED
#endif // defined(LSX_PUSHED) || defined(LASX_PUSHED)

#ifdef LSX_LASX_PUSHED
#undef LSX_LASX_PUSHED
#else
#error "loongson_unset_target.h used without loongson_set_l{a,}sx.h"
#endif

#endif // __loongarch__
