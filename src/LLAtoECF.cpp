#include "LLAtoECF.h"
#include <cmath>
#include <iostream>
#include <algorithm>

/**
 * == CONSTANTS AND EQUATIONS ==
 * WGS84 Params:
 * a = 6378137                      // semi-major axis (a)
 * b = a(1 - f)                     // semi-minor axis (b)
 * f = 1 / 298.257223563            // first eccentricity (e)
 * e = sqrt((a^2 - b^2) / a^2)      // second eccentricity (e')
 * e' = sqrt((a^2 - b^2) / b^2)     // ellipsoid flattening (f)
 * 
 * WGS84 Latitude   [degrees]
 * WGS84 Longitude  [degrees]
 * WGS84 Altitude   [kilometers]
 * 
 * X = (N + h) * cos(lat)cos(lon)
 * Y = (N + h) * cos(lat)sin(lon)
 * Z = ((b^2 / a^2) * N + h) * sin(lat)
 * 
 * phi = latitude
 * lambda = longitude
 * h = height above ellipsoid (meters)
 * N = Radius of curvature(meters), defined as: a / (sqrt(1 - e^2 * sin^2(phi)))
 * */

using namespace std;

ECFcoord LLAtoECF(const lla_data & lla){
    ECFcoord ECF;

    // CONSTANTS
    double a = 6378137;
    double b = 6356752.314245179; 
    double e = 0.081819190842621486;
    double eprime = 0.082094437949695676;

    // Convert to radians for sin cos calcs
    double lat_rads = (lla.lat * M_PI / 180.0); 
    double lon_rads = (lla.lon * M_PI / 180.0);

    double N = a / ( sqrt( 1 - (pow(e, 2.0) * pow(sin(lat_rads), 2.0))));
    double h = lla.alt * 1000; // convert from km to meters            

    ECF.time = lla.time;
    ECF.x = (N + h) * cos(lat_rads) * cos(lon_rads);
    ECF.y = (N + h) * cos(lat_rads) * sin(lon_rads);
    ECF.z = ( ((pow(b,2.0) / pow(a,2.0)) * N) + h) * sin(lat_rads);

    return ECF;
    
}

double calcDistance3D(  const double & x0, const double & y0, const double & z0,
                        const double & x1, const double & y1, const double & z1){
                        // Equation (Pythagorean Theorem):  sqrt((x1-x0)^2 + (y1-y0)^2 + (z1-z0)^2)
                        return sqrt( pow(x1-x0, 2.0) + pow(y1-y0, 2.0) + pow(z1-z0, 2.0));
                    }


// Function takes LLA Data that's been read in from CSV and converts it to ECFcoord.
// Algo then compares (time0, x0, y0, z0) and (time1, x1,y1,z1) to linearly interpolate velocity at t1
void ECFvelocity( std::vector<ECFcoord> & ECFdata){    
    double t0 = 0.0, x0 = 0.0, y0 = 0.0, z0 = 0.0; 
    double t1, x1, y1, z1;


    for(int i = 0; i < ECFdata.size(); i++){

        // Initialize tmp variables and Assign ECFdata[0].velocity = 0 per [instructions, section 1.2]
        if(t0 == 0.0){
            t0 = ECFdata[0].time;
            x0 = ECFdata[0].x;
            y0 = ECFdata[0].y;
            z0 = ECFdata[0].z;
            ECFdata[0].velocity = 0.0;
        }
        // If t0 has been initialized: 
            // Update t1, x1, y1, z1
            // Compute velocity between t0 and t1. 
            // Equation: velocity = (change in  position) / (change in  time)
            // Assign t0 = t1
            // continue
        else{
            t1 = ECFdata[i].time;
            x1 = ECFdata[i].x;
            y1 = ECFdata[i].y;
            z1 = ECFdata[i].z;    

            double dist = calcDistance3D(x0,y0,z0,x1,y1,z1);
            double vel1 = dist / (t1 - t0); // Velocity at time1
            ECFdata[i].velocity = vel1;

            t0 = t1;
            x0 = x1;
            y0 = y1;
            z0 = z1;
        }
    }
}

bool inRange(const double & low, const double & high, const double & val){
    return ((val-high) * (val-low)) <= 0;
}

double interpolateVelocity(const std::vector<ECFcoord> & ECFdata, const int & time){

    // Verify that the time requested is in the range of the data
    if(!inRange(ECFdata[0].time, ECFdata.back().time, time)){
        throw  std::invalid_argument("Time requested is outside range of data loaded!");
    }

    // returns an iterator pointing to the first element that is not less than input var: time
    auto low = std::lower_bound(ECFdata.begin(), ECFdata.end(), time, [](const ECFcoord &lhs, double rhs){
        return lhs.time < rhs;
    });
    
    int idx = int(low-ECFdata.begin());      
    
    double v1 = ECFdata[idx-1].velocity;
    double v2 = ECFdata[idx].velocity;
    double t1 = ECFdata[idx-1].time;
    double t2 = ECFdata[idx].time;

    // Linear Interpolation Equation: v = v1 + (time - time0) * (v1 - v0) / (time1 - time0)
    double v = v1 + (time - t1) * (v2 - v1) / (t2 - t1);

    return v;
}