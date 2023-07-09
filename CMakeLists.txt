include_directories(include)
file(GLOB sources include/*.h src/*.c src/*.cxx src/*.cpp include/*.hxx)
add_executable(bin/lidarslam ${sources})
