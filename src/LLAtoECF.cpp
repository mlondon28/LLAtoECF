#include "LLAtoECF.h"
#include <cmath>
#include <iostream>
#include <algorithm>

/**
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
    // double f_inv = 298.257223563;
    // double f = 1.0 / f_inv;
    double b = 6356752.314245179; // b = a * (1 - f);
    // double e =      sqrt( (pow(a, 2.0) - pow(b, 2.0)) / pow(a, 2.0) );
    // double eprime = sqrt( (pow(a, 2.0) - pow(b, 2.0)) / pow(b, 2.0) );
    double e = 0.081819190842621486;
    double eprime = 0.082094437949695676;


    // Convert to radians for sin cos calcs
    double lat_rads = (lla.lat * M_PI / 180.0); 
    double lon_rads = (lla.lon * M_PI / 180.0);

    double N = a / ( sqrt( 1 - (pow(e, 2.0) * pow(sin(lat_rads), 2.0))));
    double h = lla.alt * 1000; // meters            

    ECF.time = lla.time;
    ECF.x = (N + h) * cos(lat_rads) * cos(lon_rads);
    ECF.y = (N + h) * cos(lat_rads) * sin(lon_rads);
    ECF.z = ( ((pow(b,2.0) / pow(a,2.0)) * N) + h) * sin(lat_rads);

    return ECF;
    
}


double calcDistance3D(const double & x0, const double & y0, const double & z0,
                    const double & x1, const double & y1, const double & z1){
                        // sqrt((x1-x0)^2 + (y1-y0)^2 + (z1-z0)^2)
                        return sqrt( pow(x1-x0, 2.0) + pow(y1-y0, 2.0) + pow(z1-z0, 2.0));
                    }


// Function takes LLA Data that's been read in from CSV and converts it to ECFcoord.
// Algo then compares (time0, x0, y0, z0) and (time1, x1,y1,z1) to linearly interpolate velocity at t1
vector<double> ECFvelocity(const std::vector<ECFcoord> & ECFdata){
    vector<double> velocity;
    velocity.push_back(0.0);
    
    double t0 = 0.0, x0 = 0.0, y0 = 0.0, z0 = 0.0; 
    double t1, x1, y1, z1;

    for(auto coord : ECFdata){

        // If values not initialized, initialize. t0 should never equal zero from data.
        if(t0 == 0.0){
            t0 = coord.time;
            x0 = coord.x;
            y0 = coord.y;
            z0 = coord.z;
        }
        // If t0 has been initialized: 
            // Update t1, x1, y1, z1
            // Compute velocity between t0 and t1. v = delta position / delta time
            // Assign t0 = t1
            // continue
        else{
            t1 = coord.time;
            x1 = coord.x;
            y1 = coord.y;
            z1 = coord.z;    

            double dist = calcDistance3D(x0,y0,z0,x1,y1,z1);
            double vel1 = dist / (t1 - t0); // Velocity at time1
            velocity.push_back(vel1);

            t0 = t1;
            x0 = x1;
            y0 = y1;
            z0 = z1;
        }

    }
    return velocity;
}


double interpolateVelocity(const std::vector<ECFcoord> & ECFdata, const int & time){
    // if(ECFdata[0].time < ECFdata[1].time){cout << "t0 < t1"<<endl;}

    auto low = std::lower_bound(ECFdata.begin(), ECFdata.end(), time, [](const ECFcoord &lhs, double rhs){
        return lhs.time < rhs;
    });

    auto idx = int(low-ECFdata.begin());
    // cout << idx - 1 << idx <<idx<<endl;
    // cout.precision(17);
    // cout << "lower_bound at position " << (low - ECFdata.begin()) << endl;
    // cout << ECFdata[228].time << '\t'<< time << '\t' << ECFdata[229].time << endl;

    float percent = (time - ECFdata[idx - 1].time) / (ECFdata[idx].time - ECFdata[idx - 1].time);
    // cout << time << '\t' << ECFdata[idx - 1].time <<'\t' <<(time-ECFdata[idx - 1].time) << endl;
    cout << "Time percent: " << percent << endl;

    // cout << ECFdata[idx - 1].

    return 1.0;
}


int main()
{
    std::vector<lla_data> latLonData;
    std::vector<ECFcoord> ECFdata;
    std::string filepath = "/home/matt/projects/scitec-coding-problem/data/SciTec_code_problem_data.csv";
    char delimiter = ',';

    read_csv(filepath, latLonData, delimiter);

    for(auto record : latLonData){
        ECFcoord xyz = LLAtoECF(record);
        ECFdata.push_back(xyz);
    }

    vector<double> vel = ECFvelocity(ECFdata);

    int time1 = 1532334000, time2 = 1532335268; // seconds since Unix epoch

    double interpolatedVel = interpolateVelocity(ECFdata, time1);

    // ECEFvelocity printout
    int count = 0;
    for(auto v : vel){
        cout << v << "\t[meters / second]" << endl;
        if(count > 10){
            break;
        }
        count++;
    }

    // for(auto LLA : latLonData){
    //     ECFcoord E = LLAtoECF(LLA);
    //     cout.precision(12);
    //     cout << "X: " << E.x << " meters." << endl;
    //     cout << "Y: " << E.y << " meters." << endl;
    //     cout << "Z: " << E.z << " meters." << '\n' << endl;
    //     break;
    // }


    return 0;

}