#include <iostream>
#include "io.h"
#include "real_map.h"
#include "main.h"

using namespace std;
int main(int argc, char* argv[]) {
    lidarslam::ElevationMap elevation_map = lidarslam::read_map("dat/map.dat");
    // elevation_map.print();
    std::cout << elevation_map(-0.5, 0.5) << std::endl;
    return 0;
}
