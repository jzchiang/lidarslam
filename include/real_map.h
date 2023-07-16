#ifndef __REAL_MAP_H__
#define __REAL_MAP_H__

#include <cassert>
#include <vector>

namespace lidarslam {
class ElevationMap {
    /*
     * This class is used to interpolate a R^2 -> R^1 function
     */
public:
    ElevationMap() {}
    /*
     * This constructor creates the object from three 2-d arrays z = f(x, y)
     * It expects the 2-d arrays to be of the same size
     */
    ElevationMap(const std::vector< std::vector< float > >& x,
                 const std::vector< std::vector< float > >& y,
                 const std::vector< std::vector< float > >& z
                ) : x_(x), y_(y), z_(z) {
        assert(x.size() == y.size());
        assert(x.size() == z.size());
    }

    /*
     * Print some data for debugging purposes
     */
    void print() {
        for (size_t i = 0; i < x_.size(); i++) {
            std::cerr << x_[i][0] << std::endl;
        }
    }


private:
    std::vector< std::vector< float > > x_;
    std::vector< std::vector< float > > y_;
    std::vector< std::vector< float > > z_;
};
}
#endif
