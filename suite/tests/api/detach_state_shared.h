/* **********************************************************
 * Copyright (c) 2015-2019 Google, Inc.  All rights reserved.
 * **********************************************************/

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Google, Inc. nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL GOOGLE, INC. OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef _DETACH_STATE_SHARED_H_
#define _DETACH_STATE_SHARED_H_ 1

#define MAKE_HEX_ASM(n) HEX(n)
#define MAKE_HEX(n) 0x##n
#define MAKE_HEX_C(n) MAKE_HEX(n)

#if defined(__AVX512F__)
#    define SIMD_REG_SIZE 64
#elif defined(__AVX__)
#    define SIMD_REG_SIZE 32
#else
#    define SIMD_REG_SIZE 16
#endif
#ifdef X64
#    define NUM_SIMD_SSE_AVX_REGS 16
#    if defined(__AVX512F__)
#        define NUM_SIMD_AVX512_REGS 32
#        define NUM_SIMD_REGS NUM_SIMD_AVX512_REGS
#        define NUM_OPMASK_REGS 8
#        define OPMASK_REG_SIZE 2
#    else
#        define NUM_SIMD_REGS NUM_SIMD_SSE_AVX_REGS
#        define NUM_OPMASK_REGS 0
#        define OPMASK_REG_SIZE 0
#    endif
#else
#    define NUM_SIMD_SSE_AVX_REGS 8
#    if defined(__AVX512F__)
#        define NUM_SIMD_AVX512_REGS 8
#        define NUM_OPMASK_REGS 8
#        define OPMASK_REG_SIZE 2
#    else
#        define NUM_OPMASK_REGS 0
#        define OPMASK_REG_SIZE 0
#    endif
#    define NUM_SIMD_REGS 8
#endif

#ifdef X64
#    define XAX_BASE() 12345678abcdef01
#    define XCX_BASE() 2345678abcdef012
#    define XDX_BASE() 345678abcdef0123
#    define XBX_BASE() 45678abcdef01234
#    define XBP_BASE() 5678abcdef012345
#    define XSI_BASE() 678abcdef0123456
#    define XDI_BASE() 78abcdef01234567
#    define R8_BASE() 1234567890abcdef
#    define R9_BASE() f1234567890abcde
#    define R10_BASE() ef1234567890abcd
#    define R11_BASE() def1234567890abc
#    define R12_BASE() cdef1234567890ab
#    define R13_BASE() bcdef1234567890a
#    define R14_BASE() abcdef1234567890
#    define R15_BASE() 0abcdef123456789
/* ?MMN is formed via ?MM0 << N. */
#    define XMM0_LOW_BASE() 2384626433832795
#    define XMM0_HIGH_BASE() 3141592653589793
#    define YMMH0_LOW_BASE() 0011223344556677
#    define YMMH0_HIGH_BASE() 1122334455667788
#    define ZMMH0_0_BASE() 1112223334445556
#    define ZMMH0_1_BASE() 66777888999aaabb
#    define ZMMH0_2_BASE() bcccdddeeefff121
#    define ZMMH0_3_BASE() 23434565678789a9
#    define OPMASK0_BASE() abcbcdedef0f0424
#else
#    define XAX_BASE() 12345678
#    define XCX_BASE() 23456780
#    define XDX_BASE() 34567801
#    define XBX_BASE() 45678012
#    define XBP_BASE() 56780123
#    define XSI_BASE() 67801234
#    define XDI_BASE() 78012345
/* TODO i#3160: It will take work to finish porting the detach_state test
 * to 32-bit.
 */
#endif
#define XFLAGS_BASE() 00000ed7

#endif /* _DETACH_STATE_SHARED_H_ */
