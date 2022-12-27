//
//  SelfLib
//

#ifndef _SELFLIB_FLOW_NODE_
#define _SELFLIB_FLOW_NODE_

#include <SelfLib/Result.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Flow {

    template<
        Concept::IsResult TInput,
        Concept::IsResult TOutput
    >
    class Node {
    protected:
        
        virtual void receive(TInput input) noexcept = 0
        virtual void send(TOutput output) noexcept = 0
        
    };

}

#endif

#endif
