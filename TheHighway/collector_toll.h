#pragma once
#include "toll.h"
#include "debug.h"


class collector_toll :
    public toll
{
public:

    collector_toll(const entrance* in_belonging_node, const int in_NSegs);
    virtual ~collector_toll();

    void reinit() override;
    bool limit_is_reached() const override;
};