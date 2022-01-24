#include "collector_toll.h"

collector_toll::collector_toll(const int in_K, const int in_NSegs) :
	toll(in_K, in_NSegs)
{
}

collector_toll::~collector_toll()
{
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