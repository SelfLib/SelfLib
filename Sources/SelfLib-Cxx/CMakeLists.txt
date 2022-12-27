project(SelfLib-Cxx CXX)

file(GLOB PROJECT_HEADER_FILES
    "${PROJECT_SOURCE_DIR}/Header/*/*.hpp"
    "${PROJECT_SOURCE_DIR}/Header/*.hpp"
    "${PROJECT_SOURCE_DIR}/Header/*/*.h"
    "${PROJECT_SOURCE_DIR}/Header/*.h"
)

file(GLOB PROJECT_SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/Source/*/*.mm"
    "${PROJECT_SOURCE_DIR}/Source/*/*.m"
    "${PROJECT_SOURCE_DIR}/Source/*/*.cpp"
    "${PROJECT_SOURCE_DIR}/Source/*/*.c"
    "${PROJECT_SOURCE_DIR}/Source/*.mm"
    "${PROJECT_SOURCE_DIR}/Source/*.m"
    "${PROJECT_SOURCE_DIR}/Source/*.cpp"
    "${PROJECT_SOURCE_DIR}/Source/*.c"
)

add_library(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
