//
//  SelfLib
//

#ifndef _SELFLIB_FLOW_PIPELINE_
#define _SELFLIB_FLOW_PIPELINE_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Flow {

    template<
        Concept::IsResult TInput,
        Concept::IsResult TOutput
    >
    class Pipeline {
    public:
        
        virtual void send(TInput input) noexcept = 0
        virtual void complete() noexcept = 0
        
    };

}

#endif

#endif
