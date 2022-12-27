//
//  SelfLib
//

#ifndef _SELFLIB_RADIANS_
#define _SELFLIB_RADIANS_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template< Consept::IsReal TValue >
    struct Degrees;

    template< Consept::IsReal TValue >
    struct Radians final {
        
        using Degrees = Degrees< TValue >;
        
        inline constexpr static TValue Pi = std::numbers::pi_v< TValue >;
        
        TValue value;
        
        Radians(TValue radians) noexcept : value(radians) {
        }
        
        Radians(const Radians& radians) noexcept : value(radians.value) {
        }
        
        Radians(const Degrees& degrees) noexcept : value(degrees.value * Pi / 180) {
        }
        
        inline Degrees asDegrees() const noexcept {
            return Degrees(*this);
        }
        
        inline Radians zero() const noexcept requires Traits::IsZero< Radians > {
            return Traits::Zero< Radians >::get();
        }
        
        inline bool isZero() const noexcept requires Traits::IsZero< Radians > {
            return Traits::Zero< Radians >::is(*this);
        }
        
        inline bool isEqual(Radians other) const noexcept requires Traits::IsEqual< Radians > {
            return Traits::Equal< Radians >::is(*this, other);
        }
        
    };

}

namespace SelfLib::Traits {

    template< IsZero TValue >
    struct Zero< SelfLib::Radians< TValue > > : std::bool_constant< true > {
        
        using Type = SelfLib::Radians< TValue >;
                
        inline static Type get() noexcept {
            using Trait = Zero< TValue >;
            return Type(Trait::get());
        }
        
        inline static bool is(Type self) noexcept {
            using Trait = Zero< TValue >;
            return Trait::is(self.value);
        }
        
    };

}

namespace SelfLib::Traits {

    template< IsEqual TValue >
    struct Equal< SelfLib::Radians< TValue > > : std::bool_constant< true > {
        
        using Type = SelfLib::Radians< TValue >;
        
        inline static bool is(Type lhs, Type rhs) noexcept {
            using Equal = Equal< TValue >;
            return Equal::is(lhs.value, rhs.value);
        }
        
    };

}

#endif

#endif
