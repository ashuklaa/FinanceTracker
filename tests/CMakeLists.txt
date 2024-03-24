# enable ctest
enable_testing()

add_executable(ft_login_tests LoginManagerTests.cpp)

target_include_directories(ft_login_tests PRIVATE ../src/backend/login)

target_link_libraries(ft_login_tests gtest_main ft_login_lib)

include(GoogleTest)

gtest_discover_tests(ft_login_tests)
