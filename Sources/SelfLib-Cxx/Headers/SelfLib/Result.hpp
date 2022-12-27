//
//  SelfLib
//

#ifndef _SELFLIB_RESULT_
#define _SELFLIB_RESULT_

#include <SelfLib/Build.hpp>

#ifdef SELFLIB_LANGUAGE_CPP

namespace SelfLib::Flow {

    template<
        class TSuccess,
        class TFailure
    >
    class Result final {
    public:
        
        typedef TSuccess Success;
        typedef TFailure Failure;
        
        Result(TSuccess value) noexcept : data(value) {
        }
        
        Result(TFailure value) noexcept : data(value) {
        }
        
        template<
            class TSuccessClosure,
            class TFailureClosure
        >
        void get(
            TSuccessClosure success,
            TFailureClosure failure
        ) noexcept requires (
            std::is_invocable_v< TSuccessClosure, Success >,
            std::is_invocable_v< TFailureClosure, Failure >
        ) {
            if (this->data.index() == 0) {
                success(std::get< Success >(this->data));
            } else {
                failure(std::get< Failure >(this->data));
            }
        }
        
    private:
        std::variant< TSuccess, TFailure > data;
        
    };

}

#endif

#endif
