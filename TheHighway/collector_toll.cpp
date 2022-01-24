#include "collector_toll.h"

collector_toll::collector_toll(const int in_K, const int in_NSegs) :
	toll(in_K, in_NSegs)
{
	reinit();
}

collector_toll::~collector_toll(){}

void collector_toll::reinit()
{
	counter = 0;
	int vehicles_to_wait = K + rand() % (K + 1);
	while (waiting_vehicles.size() < vehicles_to_wait)
	{
		add();
	}
}

bool collector_toll::limit_is_reached()
{
	if (counter < K)
	{
		return false;
	}
	else
	{
		return true;
	}
}