#include "csv_utils.h"
#include <vector>
#include <string>

//!
//! DESCRIPTION: Converts from Geodedic (lat, lon, alt) coordinates to ECF coordinate frame.
//! INPUT:  <lla_data> Single Lat Lon Alt object (in seconds, degrees, degrees, kilometers)
//! OUTPUT: ECFcoord x,y,z (in meters)
//!
ECFcoord LLAtoECF(const lla_data & lla);

//!
//! DESCRIPTION: Given a vector of ECF coordinates, calculates velocity at each point.
//! INPUT: vector<ECFcoord>
//! OUTPUT: Adds calculated velocity to ECFcoord for each item in vector.
//!
void ECFvelocity(std::vector<ECFcoord> & ECF);

//!
//! DESCRIPTION: Given two sets of points (x,y,z), calculates euclidean distance between them.
//! INPUT: Two sets of 3D points
//! OUTPUT: Euclidean distance between coordinates
//!

double calcDistance3D(  const double & x0, 
                        const double & y0, 
                        const double & z0,
                        const double & x1, 
                        const double & y1, 
                        const double & z1
                        );

bool inRange(const double & low, const double & high, const double & x);

//!
//! DESCRIPTION: For any given time T that exists in the dataset [ECFdata], returns interpolated velocity 
//! INPUT: 
//!     vector<ECFcoord> (time, x,y,z)
//!     <int> time for interpolation
//! OUTPUT: velocity at requested time
//!
double interpolateVelocity(const std::vector<ECFcoord> & ECFdata, const int & time);