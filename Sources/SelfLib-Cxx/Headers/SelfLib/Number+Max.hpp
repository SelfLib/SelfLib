//
//  SelfLib
//

#include <SelfLib/Number+Compare.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

#ifndef _SELFLIB_NUMBER_MAX_
#define _SELFLIB_NUMBER_MAX_

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue max(
        TValue value,
        TValue limit
    ) noexcept {
        if (value < limit) {
            return limit;
        }
        return value;
    }

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue max(
        TValue value,
        TValue limit,
        TValue tolerance
    ) noexcept {
        if (compare< TValue >(value, limit, tolerance) == SelfLib::Compare::Less) {
            return limit;
        }
        return value;
    }

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit
    >
    inline static auto max(
        TValue value,
        TLimit limit
    ) noexcept {
        using Common = std::common_type_t< TValue, TLimit >;
        return max< Common >(Common(value), Common(limit));
    }

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit,
        Concept::IsNumeric TTolerance
    >
    inline static auto max(
        TValue value,
        TLimit limit,
        TTolerance tolerance
    ) noexcept {
        using Common = std::common_type_t< TValue, TLimit, TTolerance >;
        return max< Common >(Common(value), Common(limit), Common(tolerance));
    }

}

#else

namespace SelfLib::Private::Number {

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue max(
        TValue value,
        TValue limit
    ) noexcept;

    template<
        Concept::IsNumeric TValue
    >
    inline static TValue max(
        TValue value,
        TValue limit,
        TValue tolerance
    ) noexcept;

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit
    >
    inline static auto max(
        TValue value,
        TLimit limit
    ) noexcept;

    template<
        Concept::IsNumeric TValue,
        Concept::IsNumeric TLimit,
        Concept::IsNumeric TTolerance
    >
    inline static auto max(
        TValue value,
        TLimit limit,
        TTolerance tolerance
    ) noexcept;

}

#endif

#endif
