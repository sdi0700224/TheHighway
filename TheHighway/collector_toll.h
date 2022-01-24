#pragma once
#include "toll.h"
#include "debug.h"


class collector_toll :
    public toll
{
protected:

    bool limit_is_reached();

public:

    collector_toll(const int in_K, const int in_NSegs);
    virtual ~collector_toll();
};