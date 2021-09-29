#include "csv_utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

std::string fileToString(const string & pathToCsv){
    auto ss = ostringstream{};

    ifstream file(pathToCsv);

    if(!file.is_open()){
        cerr << "Couldn't open file!" << endl;
        exit(EXIT_FAILURE);
    }

    ss << file.rdbuf();
    return ss.str();
}

void read_csv(const std::string & pathToCsv, vector<lla_data> & aData, const char & delimiter)
{
    string content, record;
    content = fileToString(pathToCsv);

    istringstream sstream(content);
    string::size_type sz;

    int count = 0;
    while (getline(sstream, record)) {
        istringstream line(record);
        while (getline(line, record, delimiter)) {
            // Populate data. Assumes csv is formatted as [time,lat,lon,alt]
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