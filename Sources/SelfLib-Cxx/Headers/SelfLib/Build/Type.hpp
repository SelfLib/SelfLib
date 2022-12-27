//
//  SelfLib
//

#ifndef _SELFLIB_BUILD_TYPE_
#define _SELFLIB_BUILD_TYPE_

#include <SelfLib/Build/Platform.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {
    
    using Ptr = void*;

    using Bool = bool;
    
    using Size = std::size_t;
    
    using Int8 = std::int8_t;
    using UInt8 = std::uint8_t;
    using Int16 = std::int16_t;
    using UInt16 = std::uint16_t;
    using Int32 = std::int32_t;
    using UInt32 = std::uint32_t;
    using Int64 = std::int64_t;
    using UInt64 = std::uint64_t;
    
    using Real32 = float;
    using Real64 = double;
    using Real80 = long double;
    
    using AChar = char;
    using WChar = wchar_t;
    
#if (UINTPTR_MAX == UINT16_MAX)
    using Int = Int16;
    using UInt = UInt16;
    using Real = Real32;
#elif (UINTPTR_MAX == UINT32_MAX)
    using Int = Int32;
    using UInt = UInt32;
    using Real = Real32;
#elif (UINTPTR_MAX == UINT64_MAX)
    using Int = Int64;
    using UInt = UInt64;
    using Real = Real64;
#endif
    
#ifdef SELFLIB_UNICODE
    using Char = WChar;
#else
    using Char = AChar;
#endif

}

namespace SelfLib::Concept {

    template< class TValue >
    concept IsInt = std::is_integral_v< TValue >;

    template< class TValue >
    concept IsReal = std::is_floating_point_v< TValue >;

    template< class TValue >
    concept IsNumeric = IsInt< TValue > || IsReal< TValue >;

}

#endif

#endif
