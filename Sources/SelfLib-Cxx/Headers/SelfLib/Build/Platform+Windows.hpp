//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_PLATFORM_WINDOWS_
#define _SELFLIB_BUILD_PLATFORM_WINDOWS_

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)

#define SELFLIB_PLATFORM \
    SelfLib::Platform::Windows

#define SELFLIB_PLATFORM_POSIX

#include <ole2.h>
#include <shlobj.h>
#include <windows.h>
#include <winsock.h>
#include <wincodec.h>
#include <ctype.h>
#include <cmath>

#if defined(_WINDOWS) && !defined(_USRDLL)
#define SELFLIB_PLATFORM_WINDOWS_GUI
#elif defined(_CONSOLE)
#define SELFLIB_PLATFORM_WINDOWS_CONSOLE
#elif defined(_USRDLL)
#define SELFLIB_PLATFORM_WINDOWS_MODULE
#endif

#ifndef va_copy
#define va_copy(dst, src) dst = src
#endif

#endif

#endif
