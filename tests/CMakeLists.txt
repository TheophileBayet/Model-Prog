


#add_executable(test_simple test_gtest.cxx)
#target_link_libraries(test_simple gtest)

add_executable(test_class test_gtest_class.cxx)
target_link_libraries(test_class gtest vector)
add_test(test_class test_class)

add_executable(test_waves test_gtest_waves.cxx)
target_link_libraries(test_waves gtest vector)
add_test(test_waves test_waves)


add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                  DEPENDS test_class test_waves)
