#pragma once
#include "toll.h"
class digital_toll :
    public toll
{
public:

    digital_toll(const int in_K, const int in_numberOfVehicles, const int in_NSegs);

    bool limit_is_reached();

};

