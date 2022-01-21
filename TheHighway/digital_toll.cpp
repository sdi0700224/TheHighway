#include "digital_toll.h"

digital_toll::digital_toll(const int in_K, const int in_number_of_vehicles, const int in_NSegs):
	toll(in_K, in_number_of_vehicles, in_NSegs)
{
}

digital_toll::~digital_toll()
{
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
