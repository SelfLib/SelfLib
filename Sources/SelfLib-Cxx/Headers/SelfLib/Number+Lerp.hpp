//
//  SelfLib
//

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

#ifndef _SELFLIB_NUMBER_LERP_
#define _SELFLIB_NUMBER_LERP_

namespace SelfLib::Private::Number {

    template<
        Concept::IsReal TValue
    >
    inline static auto lerp(
        TValue from,
        TValue to,
        TValue progress
    ) noexcept {
        return std::lerp(from, to, progress);
    }

    template<
        Concept::IsNumeric TFrom,
        Concept::IsNumeric TTo,
        Concept::IsReal TProgress
    >
    inline static auto lerp(
        TFrom from,
        TTo to,
        TProgress progress
    ) noexcept {
        using Common = std::common_type_t< TFrom, TTo >;
        return lerp< Common, TProgress >(Common(from), Common(to), progress);
    }

}

#else

namespace SelfLib::Private::Number {

    template<
        Concept::IsReal TValue
    >
    inline static auto lerp(
        TValue from,
        TValue to,
        TValue progress
    ) noexcept;

    template<
        Concept::IsNumeric TFrom,
        Concept::IsNumeric TTo,
        Concept::IsReal TProgress
    >
    inline static auto lerp(
        TFrom from,
        TTo to,
        TProgress progress
    ) noexcept;

}

#endif

#endif
