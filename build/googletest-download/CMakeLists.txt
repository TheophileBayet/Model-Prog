# Le fichier doit être renommé CMakeLists.txt
cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "/user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/googletest-src"
  BINARY_DIR        "/user/0/.base/bayett/home/workspace/C++/lab1/TP1_bayett_mounep/build/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
