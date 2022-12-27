//
//  SelfTest
//

#ifndef _SELFTEST_NUMBER_
#define _SELFTEST_NUMBER_

#include <SelfLib/SelfLib.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfTest::Number {

    class Clamp final : SelfLib::Test::Case {
    public:
        void run() override {
            auto init = SelfLib::Number(5);
            auto value = init.clamp(10.0f, 20.0f);
            assert(value == 10);
            
            auto result = SelfLib::Result< int, bool >(1);
            result.get([] (auto success) {
            }, [] (auto failure) {
            });
        }
    };

}

#endif

#endif
