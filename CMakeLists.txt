cmake_minimum_required(VERSION 3.22)

project(LidarSlam)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

include_directories(include)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

file(GLOB sources include/*.h src/*.c src/*.cxx src/*.cpp include/*.hxx)
add_library(lidarslam ${sources})

add_executable(main src/main.cc)
target_link_libraries(main Eigen3::Eigen lidarslam)

find_package(Catch2 2)
add_executable(tests tests/test-map.cc)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain lidarslam)
include(Catch)
include(CTest)
catch_discover_tests(tests)
