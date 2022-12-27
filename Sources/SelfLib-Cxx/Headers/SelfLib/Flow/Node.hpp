//
//  SelfLib
//

#ifndef _SELFLIB_FLOW_NODE_
#define _SELFLIB_FLOW_NODE_

#include <SelfLib/Result.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Flow {

    template<
        class TInput,
        class TOutput
    >
    struct Node {
        
        void receive(TInput input, ) noexcept {
        }
        
    };

}

#endif

#endif
