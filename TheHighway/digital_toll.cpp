#include "digital_toll.h"
#include "entrance.h"

digital_toll::digital_toll(const entrance* in_belonging_node, const int in_NSegs):
	toll(in_belonging_node, in_NSegs)
{
	reinit();
}

digital_toll::~digital_toll(){}

void digital_toll::reinit()
{
	counter = 0;
	int vehicles_to_wait = 2 * belonging_node->get_K() + rand() % (2 * belonging_node->get_K() + 1);
	while (waiting_vehicles.size() < vehicles_to_wait)
	{
		add();
	}
}

bool digital_toll::limit_is_reached() const
{
	if (counter < 2 * belonging_node->get_K())
	{
		return false;
	}
	else
	{
		return true;
	}
}
