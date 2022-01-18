#include "digital_toll.h"

digital_toll::digital_toll(const int in_K, const int in_numberOfVehicles, const int in_NSegs):
	toll(in_K, in_numberOfVehicles, in_NSegs)
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
