#include "LLAtoECF.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{  
    // Initialize variables. 
    std::vector<lla_data> latLonData;
    std::vector<ECFcoord> ECFdata;
    std::string pathToCsv = "../data/SciTec_code_problem_data.csv"; // Relative Path to CSV
    char delimiter = ',';

    // Read data into latLonData
    read_csv(pathToCsv, latLonData, delimiter); 

    // Iterate through latLonData, convert to ECF coordinate. Populate ECFdata vector.
    for(auto record : latLonData){
        ECFcoord xyz = LLAtoECF(record);
        ECFdata.push_back(xyz);
    }

    // Calculate and add velocity to ECFdata. 
    ECFvelocity(ECFdata);


    int time1 = 1532334000, time2 = 1532335268; // time [seconds] since Unix epoch

    double interpolatedVel1 = interpolateVelocity(ECFdata, time1);
    double interpolatedVel2 = interpolateVelocity(ECFdata, time2);

    cout << "Interpolated Velocity at Time (" << time1 << " [s]): " << interpolatedVel1 << " [meters / second]" << endl;
    cout << "Interpolated Velocity at Time (" << time2 << " [s]): " << interpolatedVel2 << " [meters / second]\n" << endl;

    // ECF.velocity printout
    cout << "ECF.velocity for the first 10 data points:\n";
    int count = 0;
    for(auto data : ECFdata){
        if(count > 9){
            cout << "...\n\n";
            break;
        }
        cout << data.velocity << "\t[meters / second]" << endl;
        count++;
    }

    // ECF XYZ Coordinate Printout
    cout << "ECF X, Y, Z [meters]\n";
    count = 0;
    for(auto E : ECFdata){
        if(count > 9){
            cout << "...\n";
            break;
        }

        cout.precision(11);
        cout    << "X: " << E.x 
                << "\tY: " << E.y 
                << "\t\tZ: " << E.z << " \t[meters]\n";

        count++;    }


    return EXIT_SUCCESS;
}