//
//  SelfLib
//

#ifndef _SELFLIB_TEST_CASE_
#define _SELFLIB_TEST_CASE_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Test {

    class Case {
    public:
        
        virtual void run() = 0;
        
    };

}

#endif

#endif
