#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"

class ElevationMap {
public:
    ElevationMap() {}
    ElevationMap(const std::vector< std::vector< float > >& x,
                 const std::vector< std::vector< float > >& y,
                 const std::vector< std::vector< float > >& z
                ) : x_(x), y_(y), z_(z) {
    }

private:
    std::vector< std::vector< float > > x_;
    std::vector< std::vector< float > > y_;
    std::vector< std::vector< float > > z_;
};

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

using namespace std;
int main(int argc, char* argv[]) {
    ElevationMap elevation_map = read_map("dat/map.dat");
    return 0;
}
