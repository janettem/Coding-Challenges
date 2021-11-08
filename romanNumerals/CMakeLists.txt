cmake_minimum_required(VERSION 3.14)
project(romanNumerals)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/16f637fbf4ffc3f7a01fa4eceb7906634565242f.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  romanNumerals
  romanNumerals.cpp
)
target_link_libraries(
  romanNumerals
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(romanNumerals)
