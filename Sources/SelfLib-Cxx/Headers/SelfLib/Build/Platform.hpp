//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_PLATFORM_
#define _SELFLIB_BUILD_PLATFORM_

#include <SelfLib/Build/Language.hpp>
#include <SelfLib/Build/Macros.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {
    
    enum class Platform {
        Unknown,
        Windows,
        macOS,
        iOS,
        Android
    };
    
}

#endif

#include <SelfLib/Build/Platform+Android.hpp>
#include <SelfLib/Build/Platform+iOS.hpp>
#include <SelfLib/Build/Platform+macOS.hpp>
#include <SelfLib/Build/Platform+Windows.hpp>

#endif
