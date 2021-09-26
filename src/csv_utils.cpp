#include "csv_utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

std::string fileToString(const string & path){
    auto ss = ostringstream{};

    ifstream file(path);

    if(!file.is_open()){
        cerr << "Couldn't open file!" << endl;
        exit(EXIT_FAILURE);
    }

    ss << file.rdbuf();
    return ss.str();
}

void read_csv(std::string filepath, vector<lla_data> & aData, char delimiter)
{
    string content, record;
    content = fileToString(filepath);

    istringstream sstream(content);
    string::size_type sz;

    int count = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            switch (count % 4)
            {
            case 0:
                lla_data info;
                info.time = stod(record, &sz);
                break;
            case 1:
                info.lat = stod(record, &sz);
                break;
            case 2:
                info.lon = stod(record, &sz);
                break;
            case 3:
                info.alt = stod(record, &sz);
                aData.push_back(info);
                break;
            }
            count++;
        }
    }
}

// int main(){
//     vector<lla_data> data;
//     read_csv("/home/matt/projects/scitec-coding-problem/data/SciTec_code_problem_data.csv", data, ',');

//     cout.precision(12);
//     for(auto item : data){
//         cout << "Time: " << item.time << endl;
//         cout << "lat: " << item.lat << endl;
//         cout << "lon: " << item.lon << endl;
//         cout << "alt: " << item.alt << endl;
//     }

//     return 0;
// }