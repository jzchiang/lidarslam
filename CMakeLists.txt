cmake_minimum_required(VERSION 3.22)

project(LidarSlam)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
include_directories(include)
file(GLOB sources include/*.h src/*.c src/*.cxx src/*.cpp include/*.hxx)
add_executable(lidarslam src/main.cc ${sources})

find_package(Catch2 2)
add_executable(tests tests/test-map.cc ${sources})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(Catch)
include(CTest)
catch_discover_tests(tests)
