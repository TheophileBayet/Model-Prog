


#add_executable(test_simple test_gtest.cxx)
#target_link_libraries(test_simple gtest)

add_executable(test_class test_gtest_class.cxx)
target_link_libraries(test_class gtest vector)

add_executable(test_waves test_gtest_waves.cxx)
target_link_libraries(test_waves gtest vector)
