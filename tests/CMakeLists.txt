cmake_minimum_required(VERSION 3.9)
project(tests)
find_package(GTest REQUIRED)

add_executable(tests tests.cpp)

include_directories(${GTEST_INCLUDE_DIRS})

set_target_properties(tests PROPERTIES
        CMAKE_CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        )


target_link_libraries(tests ${GTEST_LIBRARIES})
add_test(tests tests)
