#ifndef __REAL_MAP_H__
#define __REAL_MAP_H__

#include <cassert>
#include <iostream>
#include <vector>

namespace lidarslam {
/*
 * This class is used to interpolate a R^2 -> R^1 function
 */
class ElevationMap {
public:
    ElevationMap() {}

    /*
     * This constructor creates the object from three 2-d arrays z = f(x, y)
    	 * With the operator() function, it can interpolate the original function
     * It expects the 2-d arrays to be of the same size
     */
    ElevationMap(const std::vector< std::vector< float > >& x,
                 const std::vector< std::vector< float > >& y,
                 const std::vector< std::vector< float > >& z
                );

    /*
     * This function evaluates the interpolation of the provided observation points
     */
    float operator()(const float x, const float y) const;

    /*
     * Print some data for debugging purposes
     */
    void print() {
        for (std::size_t i = 0; i < x_.size(); i++) {
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
