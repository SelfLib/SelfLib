//
//  SelfLib
//

#include <SelfLib/Compare.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

#ifndef _SELFLIB_NUMBER_COMPARE_
#define _SELFLIB_NUMBER_COMPARE_

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static SelfLib::Compare compare(
        TValue lhs,
        TValue rhs
    ) noexcept {
        if (lhs > rhs) {
            return Compare::Greater;
        } else if (lhs < rhs) {
            return Compare::Less;
        }
        return Compare::Equal;
    }

    template<
        Concept::IsNumeric TValue
    >
    inline static SelfLib::Compare compare(
        TValue lhs,
        TValue rhs,
        TValue tolerance
    ) noexcept {
        auto delta = lhs - rhs;
        if (delta < -tolerance) {
            return Compare::Greater;
        } else if (delta > tolerance) {
            return Compare::Less;
        }
        return Compare::Equal;
    }

    template<
        Concept::IsNumeric TLeft,
        Concept::IsNumeric TRight
    >
    inline static SelfLib::Compare compare(
        TLeft lhs,
        TRight rhs
    ) noexcept {
        using Common = std::common_type_t< TLeft, TRight >;
        return compare< Common >(Common(lhs), Common(rhs));
    }

    template<
        Concept::IsNumeric TLeft,
        Concept::IsNumeric TRight,
        Concept::IsNumeric TTolerance
    >
    inline static SelfLib::Compare compare(
        TLeft lhs,
        TRight rhs,
        TTolerance tolerance
    ) noexcept {
        using Common = std::common_type_t< TLeft, TRight, TTolerance >;
        return compare< Common >(Common(lhs), Common(rhs), Common(tolerance));
    }

}

#else

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static SelfLib::Compare compare(
        TValue lhs,
        TValue rhs
    ) noexcept;

    template<
        Concept::IsNumeric TValue
    >
    inline static SelfLib::Compare compare(
        TValue lhs,
        TValue rhs,
        TValue tolerance
    ) noexcept;

    template<
        Concept::IsNumeric TLeft,
        Concept::IsNumeric TRight
    >
    inline static SelfLib::Compare compare(
        TLeft lhs,
        TRight rhs
    ) noexcept;

    template<
        Concept::IsNumeric TLeft,
        Concept::IsNumeric TRight,
        Concept::IsNumeric TTolerance
    >
    inline static SelfLib::Compare compare(
        TLeft lhs,
        TRight rhs,
        TTolerance tolerance
    ) noexcept;

}

#endif

#endif
