//
//  SelfLib
//

#ifndef _SELFLIB_DEGREES_
#define _SELFLIB_DEGREES_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template< Consept::IsReal TValue >
    struct Radians;

    template< Consept::IsReal TValue >
    struct Degrees final {
        
        using Radians = Radians< TValue >;
        
        inline constexpr static TValue Pi = std::numbers::pi_v< TValue >;
        
        TValue value;
        
        Degrees(TValue degrees) noexcept : value(degrees) {
        }
        
        Degrees(const Degrees& degrees) noexcept : value(degrees.value) {
        }
        
        Degrees(const Radians& radians) noexcept : value(radians.value * 180 / Pi) {
        }
        
        inline Radians asRadians() const noexcept {
            return Radians(*this);
        }
        
        inline Degrees zero() const noexcept requires Traits::IsZero< Degrees > {
            return Traits::Zero< Degrees >::get();
        }
        
        inline bool isZero() const noexcept requires Traits::IsZero< Degrees > {
            return Traits::Zero< Degrees >::is(*this);
        }
        
        inline bool isEqual(Degrees other) const noexcept requires Traits::IsEqual< Degrees > {
            return Traits::Equal< Degrees >::is(*this, other);
        }
        
    };

}

#endif

#endif
