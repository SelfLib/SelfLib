//
//  SelfLib
//

#ifndef _SELFLIB_POINT_
#define _SELFLIB_POINT_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template< typename TValue >
    struct Point final {
        
        typedef Number< TValue > Field;
        
        Field x;
        Field y;
        
        Point(Field x, Field y) noexcept : x(x), y(y) {
        }
        
        Point(const Point& point) noexcept : x(point.x), y(point.y) {
        }
        
        inline Point wrap() const noexcept {
            return Point(y, x);
        }
        
        inline Point perpendicular() const noexcept {
            return Point(y, -x);
        }
        
        static inline Point infinity() noexcept requires Traits::IsInfinity< Point > {
            return Traits::Infinity< Point >::get();
        }
        
        inline bool isInfinity() const noexcept requires Traits::IsInfinity< Point > {
            return Traits::Infinity< Point >::is(*this);
        }
        
        SELFLIB_EXTENSION_EQUAL_TRAIT(Point)
        SELFLIB_EXTENSION_LERP_TRAIT(Point)
        SELFLIB_EXTENSION_ZERO_TRAIT(Point)
        
    };

}

namespace SelfLib::Traits {

    template< IsInfinity TValue >
    struct Infinity< SelfLib::Point< TValue > > final : std::bool_constant< true > {
        
        typedef SelfLib::Point< TValue > Value;
        typedef typename Value::Field SubValue;
        typedef Infinity< SubValue > SubTrait;
                
        inline static Value get() noexcept {
            return Value(
                SubTrait::get(),
                SubTrait::get()
            );
        }
        
        inline static bool is(Value self) noexcept {
            return SubTrait::is(self.x)
                && SubTrait::is(self.y);
        }
        
    };

}

namespace SelfLib::Traits {

    template< IsEqual TValue >
    struct Equal< SelfLib::Point< TValue > > final : std::bool_constant< true > {
        
        typedef SelfLib::Point< TValue > Value;
        typedef typename Value::Field SubValue;
        typedef Equal< SubValue > SubTrait;
        
        inline static bool is(Value lhs, Value rhs) noexcept {
            return SubTrait::is(lhs.x, rhs.x)
                && SubTrait::is(lhs.y, rhs.y);
        }
        
    };

}

namespace SelfLib::Traits {

    template< typename TValue, std::floating_point TProgress >
    requires IsLerp< SelfLib::Number< TValue >, TProgress >
    struct Lerp< SelfLib::Point< TValue >, TProgress > final : std::bool_constant< true > {
        
        typedef SelfLib::Point< TValue > Value;
        typedef typename Value::Field SubValue;
        typedef TProgress Progress;
        typedef Lerp< SubValue, Progress > SubTrait;
        typedef SelfLib::Point< typename SubTrait::Result > Result;
        
        inline static Result perform(Value from, Value to, Progress progress) noexcept {
            return Result(
                SubTrait::perform(from.x, to.x, progress),
                SubTrait::perform(from.y, to.y, progress)
            );
        }
        
    };

}

namespace SelfLib::Traits {

    template< IsZero TValue >
    struct Zero< SelfLib::Point< TValue > > final : std::bool_constant< true > {
        
        typedef SelfLib::Point< TValue > Value;
        typedef typename Value::Field SubValue;
        typedef Zero< SubValue > SubTrait;
                
        inline static Value get() noexcept {
            return Value(
                SubTrait::get(),
                SubTrait::get()
            );
        }
        
        inline static bool is(Value self) noexcept {
            return SubTrait::is(self.x)
                && SubTrait::is(self.y);
        }
        
    };

}

#endif

#endif
