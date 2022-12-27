//
//  SelfLib
//

#include <SelfLib/Build.hpp>

namespace SelfLib {

    Platform Build::platform() noexcept {
#ifdef SELFLIB_PLATFORM
        return SELFLIB_PLATFORM;
#else
        return SelfLib::Platform::Unknown;
#endif
	}

	/*
    Literal::String Build::platformString() noexcept {
		return SELFLIB_PLATFORM_STRING;
	}
    */

}
