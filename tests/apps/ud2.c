/**************************************************************************
 *
 * Copyright 2009-2106 Jose Fonseca
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. NO EVENT SHALL
 * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OF OR CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS THE SOFTWARE.
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 **************************************************************************/

#include <intrin.h>

#include "macros.h"

#if defined(__MINGW32__)
#if defined(_M_ARM64)
#define __ud2()  asm volatile ("udf #0xdead")
#elif defined(_M_ARM)
// https://stackoverflow.com/a/67309579
#define __ud2()  asm volatile (".inst 0x0000dead")
#else
#define __ud2()  asm volatile ("ud2")
#endif
#endif

int
main(int argc, char *argv[])
{
    __ud2();  LINE_BARRIER

    return 0;
}

// CHECK_STDERR: /  ud2\.exe\!main\+0x[0-9a-f]+  \[.*\bud2\.c @ 46\]/
// CHECK_EXIT_CODE: 0xC000001D
