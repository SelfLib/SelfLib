cmake_minimum_required(VERSION 3.22)

# CONFIGURE

set(CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}/Sources/SelfLib-Cxx/Header)
include_directories(${PROJECT_SOURCE_DIR}/Sources/SelfTest-Cxx/Header)

# LIBRARY

add_subdirectory(${PROJECT_SOURCE_DIR}/Sources/SelfLib-Cxx)

# TEST

enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/Sources/SelfTest-Cxx)
