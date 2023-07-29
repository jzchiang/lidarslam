#include <iostream>

// #include <Eigen/Dense>

#include "io.h"
#include "real_map.h"
#include "main.h"

using namespace std;
int main(int argc, char* argv[]) {
    lidarslam::ElevationMap elevation_map = lidarslam::read_map("dat/map.dat");
    std::cout << elevation_map(-0.5, 0.5) << std::endl;
		// Eigen::Vector3d vec;
    return 0;
}
