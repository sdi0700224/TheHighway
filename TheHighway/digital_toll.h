#pragma once
#include "toll.h"
#include "debug.h"


class digital_toll :
    public toll
{
protected:

    bool limit_is_reached();

public:

    digital_toll(const int in_K, const int in_NSegs);
    virtual ~digital_toll();
};

