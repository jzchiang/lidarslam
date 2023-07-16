#ifndef __IO_H__
#define __IO_H__
#include <fstream>
#include <vector>

#include "real_map.h"

namespace lidarslam {
ElevationMap read_map(const std::string& filename) {
	/*
	 * This function reads data from a .dat file to populate an ElevationMap object
	 */
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

#endif
