//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_
#define _SELFLIB_BUILD_

#include <SelfLib/Build/Language.hpp>
#include <SelfLib/Build/Macros.hpp>
#include <SelfLib/Build/Platform.hpp>
#include <SelfLib/Build/Type.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

	class Build final {

	public:

		static Platform platform() noexcept;

	};

}

#endif

#endif
