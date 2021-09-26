#pragma once

struct lla_data
{
    double time, lat, lon, alt;
};

struct ECFcoord
{
    double time = 0.0, x = 0.0, y = 0.0, z = 0.0, velocity = -1.0;
};
