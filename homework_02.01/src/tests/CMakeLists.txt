include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TOP_TREE}/tests)

add_executable(test_main test_main.cpp)
target_include_directories(test_main PUBLIC ${TOP_TREE}/Headers PUBLIC GSL_INCLUDE_DIR)
target_link_directories(test_main PUBLIC ${TOP_TREE}/Libraries PUBLIC GSL_LIB_DIR)
target_link_libraries(test_main PUBLIC GTest::gtest_main PUBLIC GTest::gmock_main PUBLIC quad_module PUBLIC data_frame PUBLIC gsl PUBLIC gslcblas)

include(GoogleTest)
gtest_discover_tests(test_main)
