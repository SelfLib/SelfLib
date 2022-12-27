//
//  SelfLib
//

#ifndef _SELFLIB_NUMBER_
#define _SELFLIB_NUMBER_

#include <SelfLib/Build.hpp>
#include <SelfLib/Number+Clamp.hpp>
#include <SelfLib/Number+Compare.hpp>
#include <SelfLib/Number+Lerp.hpp>
#include <SelfLib/Number+Max.hpp>
#include <SelfLib/Number+Min.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template<
        Concept::IsNumeric TValue
    >
    struct Number final {
        
        typedef TValue Value;
        
        Value value;
        
        Number(Value value) noexcept : value(value) {
        }
        
        Number(const Number& other) noexcept : value(other.value) {
        }
        
        // MARK: Operator
        
        template<
            Concept::IsNumeric TOther
        >
        inline Number& operator = (TOther other) noexcept {
            this->value = other;
            return *this;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline Number& operator = (Number< TOther > other) noexcept {
            this->value = other.value;
            return *this;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator == (TOther other) const noexcept {
            return this->compare(other) == Compare::Equal;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator == (Number< TOther > other) const noexcept {
            return this->compare(other) == Compare::Equal;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator != (TOther other) const noexcept {
            return this->compare(other) != Compare::Equal;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator != (Number< TOther > other) const noexcept {
            return this->compare(other) != Compare::Equal;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator > (TOther other) const noexcept {
            return this->compare(other) == Compare::Greater;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator > (Number< TOther > other) const noexcept {
            return this->compare(other) == Compare::Greater;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator >= (TOther other) const noexcept {
            return this->compare(other) != Compare::Less;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator >= (Number< TOther > other) const noexcept {
            return this->compare(other) != Compare::Less;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator < (TOther other) const noexcept {
            return this->compare(other) == Compare::Less;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator < (Number< TOther > other) const noexcept {
            return this->compare(other) == Compare::Less;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator <= (TOther other) const noexcept {
            return this->compare(other) != Compare::Greater;
        }
        
        template<
            Concept::IsNumeric TOther
        >
        inline bool operator <= (Number< TOther > other) const noexcept {
            return this->compare(other) != Compare::Greater;
        }
        
        // MARK: Static
        
        [[nodiscard]]
        inline static Number epsilon() noexcept requires Concept::IsReal< TValue > {
            return Number(std::numeric_limits< Value >::epsilon());
        }
        
        [[nodiscard]]
        inline static Number infinity() noexcept requires Concept::IsReal< TValue > {
            return Number(std::numeric_limits< Value >::infinity());
        }
        
        [[nodiscard]]
        inline static Number pi() noexcept requires Concept::IsReal< TValue > {
            return Number(std::numbers::pi_v< TValue >);
        }
        
        [[nodiscard]]
        inline static Number max() noexcept {
            return Number(std::numeric_limits< Value >::max());
        }
        
        [[nodiscard]]
        inline static Number min() noexcept {
            return Number(std::numeric_limits< Value >::min());
        }
        
        [[nodiscard]]
        inline static Number zero() noexcept {
            return Number(0);
        }
        
        // MARK: Clamp
        
        template<
            Concept::IsNumeric TLimit
        >
        [[nodiscard]]
        inline auto clamp(
            TLimit lower,
            TLimit upper
        ) const noexcept {
            auto result = Private::Number::clamp(this->value, lower, upper);
            return Number< decltype(result) >(result);
        }
        
        template<
            Concept::IsNumeric TLimit
        >
        [[nodiscard]]
        inline auto clamp(
            Number< TLimit > lower,
            Number< TLimit > upper
        ) const noexcept {
            return this->clamp(lower.value, upper.value);
        }
        
        template<
            Concept::IsNumeric TLimit,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline auto clamp(
            TLimit lower,
            TLimit upper,
            TTolerance tolerance
        ) const noexcept {
            auto result = Private::Number::clamp(this->value, lower, upper, tolerance);
            return Number< decltype(result) >(result);
        }
        
        template<
            Concept::IsNumeric TLimit,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline auto clamp(
            Number< TLimit > lower,
            Number< TLimit > upper,
            Number< TTolerance > tolerance
        ) const noexcept {
            return this->clamp(lower.value, upper.value, tolerance.value);
        }
        
        // MARK: Compare
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Compare compare(
            TOther other
        ) const noexcept {
            return Private::Number::compare(this->value, other);
        }
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Compare compare(
            Number< TOther > other
        ) const noexcept {
            return Private::Number::compare(this->value, other.value);
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Compare compare(
            TOther other,
            TTolerance tolerance
        ) const noexcept {
            return Private::Number::compare(this->value, other, tolerance);
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Compare compare(
            Number< TOther > other,
            Number< TTolerance > tolerance
        ) const noexcept {
            return Private::Number::compare(this->value, other.value, tolerance.value);
        }
        
        // MARK: Lerp
        
        template<
            Concept::IsNumeric TTo,
            Concept::IsReal TProgress
        >
        [[nodiscard]]
        inline auto lerp(
            TTo to,
            TProgress progress
        ) const noexcept {
            return Number(Private::Number::lerp(this->value, to, progress));
        }
        
        template<
            Concept::IsNumeric TTo,
            Concept::IsReal TProgress
        >
        [[nodiscard]]
        inline auto lerp(
            Number< TTo > to,
            TProgress progress
        ) const noexcept {
            return Number(Private::Number::lerp(this->value, to.value, progress));
        }
        
        // MARK: Max
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Number max(
            TOther other
        ) const noexcept {
            return Number(Private::Number::max(this->value, other));
        }
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Number max(
            Number< TOther > other
        ) const noexcept {
            return Number(Private::Number::max(this->value, other.value));
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Number max(
            TOther other,
            TTolerance tolerance
        ) const noexcept {
            return Number(Private::Number::max(this->value, other, tolerance));
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Number max(
            Number< TOther > other,
            Number< TTolerance > tolerance
        ) const noexcept {
            return Number(Private::Number::max(this->value, other.value, tolerance.value));
        }
        
        // MARK: Min
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Number min(
            TOther other
        ) const noexcept {
            return Number(Private::Number::min(this->value, other));
        }
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Number min(
            Number< TOther > other
        ) const noexcept {
            return Number(Private::Number::min(this->value, other.value));
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Number min(
            TOther other,
            TTolerance tolerance
        ) const noexcept {
            return Number(Private::Number::min(this->value, other, tolerance));
        }
        
        template<
            Concept::IsNumeric TOther,
            Concept::IsNumeric TTolerance
        >
        [[nodiscard]]
        inline Number min(
            Number< TOther > other,
            Number< TTolerance > tolerance
        ) const noexcept {
            return Number(Private::Number::min(this->value, other.value, tolerance.value));
        }

    };


}

#endif

#endif
