//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_MACROS_
#define _SELFLIB_BUILD_MACROS_

#include <SelfLib/Build/Platform.hpp>

#define _SELFLIB_TO_STRING(a) \
    # a

#define SELFLIB_TO_STRING(a) \
    _SELFLIB_TO_STRING(a)

#define _SELFLIB_CONCAT_2(a, b) \
    a ## b

#define _SELFLIB_CONCAT_3(a, b, c) \
    a ## b ## c

#define _SELFLIB_CONCAT_4(a, b, c, d) \
    a ## b ## c ## d

#define _SELFLIB_CONCAT_5(a, b, c, d, e) \
    a ## b ## c ## d ## e

#define SELFLIB_CONCAT_2(a, b) \
    _SELFLIB_CONCAT_2(a, b)

#define SELFLIB_CONCAT_3(a, b, c) \
    _SELFLIB_CONCAT_3(a, b, c)

#define SELFLIB_CONCAT_4(a, b, c, d) \
    _SELFLIB_CONCAT_4(a, b, c, d)

#define SELFLIB_CONCAT_5(a, b, c, d, e) \
    _SELFLIB_CONCAT_5(a, b, c, d, e)

#define SELFLIB_ALIGN(x, a) \
    (((x) + ((a) - 1)) & (~((a) - 1)))

#define SELFLIB_ALIGN_16(x) \
    SELFLIB_ALIGN(x, 16)

#define SELFLIB_ALIGN_32(x) \
    SELFLIB_ALIGN(x, 32)

#define SELFLIB_ALIGN_64(x) \
    SELFLIB_ALIGN(x, 64)

#define SELFLIB_BIT(x) \
    (1 << (x))

#define SELFLIB_UNUSED(arg) \
    (void)arg

#define SELFLIB_EXPAND(...) \
    __VA_ARGS__

#define SELFLIB_ASTRING(text) \
    text

#define SELFLIB_WSTRING(text) \
    L##text

#if !defined(SELFLIB_UNICODE)

#define SELFLIB_STRING(text) \
    SELFLIB_ASTRING(text)

#else

#define SELFLIB_STRING(text) \
    SELFLIB_WSTRING(text)

#endif

#endif
