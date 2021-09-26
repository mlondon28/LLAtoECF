#pragma once

#include "gps_structs.h"
#include <vector>
#include <string>

//!
//! INPUT: Path to csv to read.
//! OUTPUT: string of csv
//!
std::string fileToString(const std::string & pathToCsv);

//!
//! DESCRIPTION: Reads [time,lat,lon,alt] formatted CSV
//! INPUT: 
//!     pathToCsv: Filepath to csv of interest
//!     data:   time (seconds since unix epoch)
//!             latitude (degrees)
//!             longitude (degrees)
//!             altitude (kilometers)
//! OUTPUT:
//!     input vector<lla_data> data gets filled out with data.
//!
void read_csv(const std::string & pathToCsv, std::vector<lla_data> & data, const char & delimiter);
