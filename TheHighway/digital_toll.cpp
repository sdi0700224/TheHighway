#include "digital_toll.h"

digital_toll::digital_toll(const int in_K, const int in_NSegs):
	toll(in_K, in_NSegs)
{
	reinit();
}

digital_toll::~digital_toll(){}

void digital_toll::reinit()
{
	counter = 0;
	int vehicles_to_wait = 2 * K + rand() % (2 * K + 1);
	while (waiting_vehicles.size() < vehicles_to_wait)
	{
		add();
	}
}

bool digital_toll::limit_is_reached()
{
	if (counter < 2 * K)
	{
		return false;
	}
	else
	{
		return true;
	}
}
