//
//  SelfLib
//

#ifndef _SELFLIB_TEST_RUNNER_
#define _SELFLIB_TEST_RUNNER_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Test {

    class Runner {
    public:
        
        virtual void run() = 0;
        
    };

}

#endif

#endif
