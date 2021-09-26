#include "csv_utils.h"
#include <vector>
#include <string>


// Input:  Single Lat Lon Alt object (in degrees, degrees, kilometers)
// Output: ECFcoord object (in meters)
ECFcoord LLAtoECF(const lla_data & lla);

// Input: dataset. vector<lla_data>
// Output: vector<double> velocity
std::vector<double> ECFvelocity(const std::vector<ECFcoord> & ECF);

// Input: Two sets of 3D points
// Output: Euclidean distance between coordinates
double calcDistance3D(  const double & x0, 
                        const double & y0, 
                        const double & z0,
                        const double & x1, 
                        const double & y1, 
                        const double & z1
                        );

// Input: Vector of ECFdata (time, x,y,z)
// Output: velocity at requested time
double interpolateVelocity(const std::vector<ECFcoord> & ECFdata, const int & time);