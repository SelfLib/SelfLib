//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_PLATFORM_IOS_
#define _SELFLIB_BUILD_PLATFORM_IOS_

#if defined(__APPLE__) && defined(__MACH__)

#include <TargetConditionals.h>

#if (TARGET_OS_IPHONE == 1) || (TARGET_IPHONE_SIMULATOR == 1)

#define SELFLIB_PLATFORM \
    SelfLib::Platform::iOS

#define SELFLIB_PLATFORM_COCOA
#define SELFLIB_PLATFORM_POSIX

#include <Availability.h>
#include <objc/runtime.h>
#include <objc/message.h>

#if defined(SELFLIB_LANGUAGE_OBJC)
#import <Foundation/Foundation.h>
#endif

#endif

#endif

#endif
