//
//  SelfLib
//

#ifndef _SELFLIB_PERCENT_
#define _SELFLIB_PERCENT_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib {

    template< Concept::IsReal TValue >
    struct Percent final {
        
        TValue value;
        
        Percent(TValue value) noexcept : value(value) {
        }
        
        Percent(const Percent& percent) noexcept : value(percent.value) {
        }
        
    };

}

#endif

#endif
