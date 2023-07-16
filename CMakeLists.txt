cmake_minimum_required(VERSION 3.22)

project(LidarSlam)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
include_directories(include)
file(GLOB sources include/*.h src/*.c src/*.cxx src/*.cpp include/*.hxx)
add_executable(lidarslam ${sources})
