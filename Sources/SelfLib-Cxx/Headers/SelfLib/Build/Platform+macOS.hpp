//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_PLATFORM_MACOS_
#define _SELFLIB_BUILD_PLATFORM_MACOS_

#if defined(__APPLE__) && defined(__MACH__)

#include <TargetConditionals.h>

#if (TARGET_OS_MAC == 1) && (TARGET_OS_IPHONE == 0)

#define SELFLIB_PLATFORM \
    SelfLib::Platform::macOS

#define SELFLIB_PLATFORM_COCOA
#define SELFLIB_PLATFORM_POSIX

#include <Availability.h>
#include <objc/runtime.h>
#include <objc/message.h>

#endif

#endif

#endif
