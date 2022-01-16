#include "digital_toll.h"

digital_toll::digital_toll(const int in_K, const int in_numberOfVehicles):
	toll(in_K, in_numberOfVehicles)
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
