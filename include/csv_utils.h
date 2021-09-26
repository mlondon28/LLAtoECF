#pragma once

#include "gps_structs.h"
#include <vector>
#include <string>


// read_csv takes filename, (LLA struct), and delimiter
std::string fileToString(const std::string & path);

void read_csv(std::string filename, std::vector<lla_data> & data, char delimiter);
