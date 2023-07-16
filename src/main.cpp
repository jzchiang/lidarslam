#include <iostream>
#include <fstream>
#include <vector>
#include "real_map.h"
#include "main.h"

namespace lidarslam {
ElevationMap read_map(const std::string& filename) {
    std::ifstream ifs;
    int m, n;
    ifs.open(filename, std::ifstream::in);
    ifs >> m;
    ifs >> n;
    std::vector< std::vector< float > > x(m, std::vector<float>(n, 0.));
    std::vector< std::vector< float > > y(m, std::vector<float>(n, 0.));
    std::vector< std::vector< float > > z(m, std::vector<float>(n, 0.));
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            ifs >> x[i][j];
            ifs >> y[i][j];
            ifs >> z[i][j];
        }
    }
    ifs.close();
    ElevationMap elevation_map(x, y, z);
    return elevation_map;
}
}

using namespace std;
int main(int argc, char* argv[]) {
    lidarslam::ElevationMap elevation_map = lidarslam::read_map("dat/map.dat");
    elevation_map.print();
    return 0;
}
