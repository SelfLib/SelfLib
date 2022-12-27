//
//  SelfTest
//

#ifndef _SELFTEST_
#define _SELFTEST_

#include <SelfTest/Number.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

extern "C" {

    void SelfTestRun();

}

#elifdef SELFLIB_LANGUAGE_C

void SelfTestRun();

#endif

#endif
