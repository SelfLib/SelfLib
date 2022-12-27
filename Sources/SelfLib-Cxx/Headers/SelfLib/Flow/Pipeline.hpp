//
//  SelfLib
//

#ifndef _SELFLIB_FLOW_PIPELINE_
#define _SELFLIB_FLOW_PIPELINE_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Flow {

    template<
        class TInput,
        class TOutput
    >
    struct Pipeline final {
    public:
        
        void send(TInput input) {
        }
        
        void complete() {
        }
        
    };

}

#endif

#endif
