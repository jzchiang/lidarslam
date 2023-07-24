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
		size_t jx = (ix+1 < x_.at(0).size()) ? ix+1 : ix-1;
    float xi = (x - x_.at(0)[ix])/(x_.at(0)[jx] - x_.at(0)[ix]);
    size_t iy =
        std::lower_bound(
    y_.begin(), y_.end(), y, [](auto a, auto b) {
        return a.at(0) < b;
    }
        ) - y_.begin();
		size_t jy = (iy+1 < y_.size()) ? iy+1 : iy-1;
    float eta = (y - y_[iy].at(0))/(y_[jy].at(0) - y_[iy].at(0));
    return (1.-xi)*(1.-eta)*z_[iy][ix] +
           (1.-xi)*eta*z_[jy][ix] +
           xi*(1.-eta)*z_[iy][jx] +
           xi*eta*z_[jy][jx];
}
}
