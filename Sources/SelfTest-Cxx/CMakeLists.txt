project(SelfTest-Cxx CXX)

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

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SelfLib-Cxx)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
