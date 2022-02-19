#include "collector_toll.h"
#include "entrance.h"

collector_toll::collector_toll(const entrance* in_belonging_node, const int in_NSegs) :
	toll(in_belonging_node, in_NSegs)
{
	reinit();
}

collector_toll::~collector_toll(){}

void collector_toll::reinit()
{
	counter = 0;
	int vehicles_to_wait = belonging_node->get_K() + rand() % (belonging_node->get_K() + 1);
	while (waiting_vehicles.size() < vehicles_to_wait)
	{
		add();
	}
}

bool collector_toll::limit_is_reached() const
{
	if (counter < belonging_node->get_K())
	{
		return false;
	}
	else
	{
		return true;
	}
}