#pragma once
#include "toll.h"
class digital_toll :
    public toll
{
public:

    digital_toll(const int in_K, const int in_numberOfVehicles, const int in_NSegs);
    virtual ~digital_toll();

    bool limit_is_reached();

};

