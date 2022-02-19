#pragma once
#include "toll.h"
#include "debug.h"


class digital_toll :
    public toll
{
public:

    digital_toll(const entrance* in_belonging_node, const int in_NSegs);
    virtual ~digital_toll();

    void reinit() override;
    bool limit_is_reached() const override;
};

