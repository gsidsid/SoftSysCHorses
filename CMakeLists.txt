project (SoftSysCHorses)
include (GoogleTest)
cmake_minimum_required (VERSION 2.6)
enable_testing()

include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory (src)
add_executable (kmeans kmeans.c)
add_executable (parallel_distance_test test/parallel_distance_test.cpp)
target_link_libraries (kmeans ${PROJECT_NAME})
target_link_libraries (parallel_distance_test gtest_main gtest ${PROJECT_NAME})

gtest_discover_tests (parallel_distance_test)
