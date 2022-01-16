#include "attiki_odos.h"

attiki_odos::attiki_odos(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), segments(in_NSegs), no_of_vehicles(in_NSegs*in_SegmentCapacity), SegmentCapacity(in_SegmentCapacity) //Wrong no_of_veh init
{
	for (int i = 0; i < in_NSegs; i++)
	{
		segments[i] = new segment(in_NSegs, in_K, in_Percent, in_SegmentCapacity, i, i > 0 ? segments[(long long)i - 1] : NULL, i < in_NSegs - 1 ? segments[(long long)i + 1] : NULL);
	}
	cout << "Highway operating..\n";
}

attiki_odos::~attiki_odos()
{
	for (int i = 0; i < segments.size(); i++)
	{
		delete segments[i];
	}
}

void attiki_odos::operate()
{
	for (int i = (int)segments.size() - 1; i >= 0; i--)
	{
		segments[i]->operate();
	}
}
