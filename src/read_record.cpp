// #include "csv_utils.h"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>
// #include <map>

// using namespace std;

// string readFileIntoString(const string& path){
//     auto ss = ostringstream{};
//     ifstream input_file(path);
//     if(!input_file.is_open()){
//         cerr << "Could not open the file - '"
//              << path << "'" << endl;
//         exit(EXIT_FAILURE);
//     }
//     ss << input_file.rdbuf();
//     return ss.str();
// }


// int main()
// {
//     string filename("/home/matt/projects/scitec-coding-problem/data/SciTec_code_problem_data.csv");
//     string file_contents;
//     std::map<int, std::vector<string>> csv_contents;
//     vector<lla_data> data;
//     char delimiter = ',';

//     file_contents = readFileIntoString(filename);

//     istringstream sstream(file_contents);
//     std::vector<string> items;
//     string record;
//     std::string::size_type sz;

//     int counter = 0;
//     int count = 0;
//     while (std::getline(sstream, record)) {
//         istringstream line(record);
//         // cout << line.str() << endl;
//         while (std::getline(line, record, delimiter)) {
//             // cout << record << endl;
//             // items.push_back(record);
//             // break;
//             switch (count % 4)
//             {
//             case 0:
//                 lla_data info;
//                 // put into LLA_DATA.time
//                 info.time = stod(record, &sz);
//                 break;
//             case 1:
//                 info.lat = stod(record, &sz);
//                 break;
//             case 2:
//                 info.lon = stod(record, &sz);
//                 break;
//             case 3:
//                 info.alt = stod(record, &sz);
//                 data.push_back(info);
//                 break;
//             }
//             count++;
//         }
//         // double time = std::stod(items[0], &sz);
//         cout.precision(12);
//         cout << '\n';
//         cout    << data[0].time << '\n'
//                 << data[0].lat  << '\n'
//                 << data[0].lon  << '\n'
//                 << data[0].alt  << '\n'
//                 << endl;
                
//         csv_contents[counter] = items;
//         items.clear();
//         counter += 1;
//         break;
//     }
//     exit(EXIT_SUCCESS);
// }