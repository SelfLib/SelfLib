//
//  SelfLib
//

#include <SelfLib/Number+Compare.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

#ifndef _SELFLIB_NUMBER_CLAMP_
#define _SELFLIB_NUMBER_CLAMP_

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue clamp(
        TValue value,
        TValue lower,
        TValue upper
    ) noexcept {
        if (value < lower) {
            return lower;
        } else if (value > upper) {
            return upper;
        }
        return value;
    }

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue clamp(
        TValue value,
        TValue lower,
        TValue upper,
        TValue tolerance
    ) noexcept {
        if (compare< TValue >(value, lower, tolerance) == SelfLib::Compare::Less) {
            return lower;
        } else if (compare< TValue >(value, upper, tolerance) == SelfLib::Compare::Greater) {
            return upper;
        }
        return value;
    }

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit
    >
    inline static auto clamp(
        TValue value,
        TLimit lower,
        TLimit upper
    ) noexcept {
        using Common = std::common_type_t< TValue, TLimit >;
        return clamp< Common >(Common(value), Common(lower), Common(upper));
    }

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit,
        Concept::IsNumeric TTolerance
    >
    inline static auto clamp(
        TValue value,
        TLimit lower,
        TLimit upper,
        TTolerance tolerance
    ) noexcept {
        using Common = std::common_type_t< TValue, TLimit, TTolerance >;
        return clamp< Common >(Common(value), Common(lower), Common(upper), Common(tolerance));
    }

}

#else

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue clamp(
        TValue value,
        TValue lower,
        TValue upper
    ) noexcept;

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue clamp(
        TValue value,
        TValue lower,
        TValue upper,
        TValue tolerance
    ) noexcept;

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit
    >
    inline static auto clamp(
        TValue value,
        TLimit lower,
        TLimit upper
    ) noexcept;

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit,
        Concept::IsNumeric TTolerance
    >
    inline static auto clamp(
        TValue value,
        TLimit lower,
        TLimit upper,
        TTolerance tolerance
    ) noexcept;

}

#endif

#endif
