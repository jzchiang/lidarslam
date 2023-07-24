#include <vector>

#include <catch2/catch.hpp>

#include "real_map.h"

TEST_CASE("Test corners of a single grid square", "[real_map]"){
	std::vector< std::vector<float> > x = {{0., 1.}, {0., 1.}};
	std::vector< std::vector<float> > y = {{0., 0.}, {1., 1.}};
	std::vector< std::vector<float> > z = {{0., 1.}, {2., 3.}};
	lidarslam::ElevationMap elevation_map(x, y, z);
	REQUIRE( elevation_map(0., 0.) == 0. );
	REQUIRE( elevation_map(1., 0.) == 1. );
	REQUIRE( elevation_map(0., 1.) == 2. );
	REQUIRE( elevation_map(1., 1.) == 3. );
}
