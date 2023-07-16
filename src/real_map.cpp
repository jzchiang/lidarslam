#include <algorithm>

#include "real_map.h"

namespace lidarslam {
ElevationMap::ElevationMap(const std::vector< std::vector< float > >& x,
                           const std::vector< std::vector< float > >& y,
                           const std::vector< std::vector< float > >& z
                          ) : x_(x), y_(y), z_(z) {
    assert(x.size() == z.size());
    assert(y.size() == z.size());
}

float
ElevationMap::operator()(const float x, const float y) const {
    size_t ix =
        std::lower_bound(
            x_.at(0).begin(), x_.at(0).end(), x
        ) - x_.at(0).begin();
    std::cout << ix << std::endl;
    size_t iy =
        std::lower_bound(
    y_.begin(), y_.end(), y, [](auto a, auto b) {
        return a.at(0) < b;
    }
        ) - y_.begin();
    std::cout << iy << std::endl;
    return z_[iy][ix];
}
}
