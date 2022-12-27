//
//  SelfLib
//

#ifndef _SELFLIB_RANGE_
#define _SELFLIB_RANGE_

#include <SelfLib/Number.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template<
        Concept::IsNumeric TValue
    >
    struct Range final {
        
        typedef Number< TValue > Field;
        
        Field lower;
        Field upper;
        
        Range(
            Field lower,
            Field upper
        ) noexcept :
            lower(lower),
            upper(upper) {
        }
        
        // MARK: Compare
        
        template<
            Concept::IsNumeric TOther
        >
        [[nodiscard]]
        inline Compare compare(
            Range< TOther > other
        ) const noexcept {
            auto lcr = this->lower.compare(other.lower);
            auto ucr = this->upper.compare(other.upper);
            switch lcr {
            case Compare::NotEqual:
                switch ucr {
                case Compare::NotEqual: return
                case Compare::Equal:
                case Compare::Greater:
                case Compare::Less:
                }
            case Compare::Equal:
            case Compare::Greater:
            case Compare::Less:
            }
            return ;
        }
        
    };

}

#endif

#endif
