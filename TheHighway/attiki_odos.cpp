#include "attiki_odos.h"

attiki_odos::attiki_odos(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), segments(), no_of_vehicles(0), SegmentCapacity(in_SegmentCapacity) //Wrong no_of_veh init
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < in_NSegs; i++)
	{
		segments.push_back(new segment(in_NSegs, in_K, in_Percent, in_SegmentCapacity, i, NULL, NULL));
		no_of_vehicles += segments[i]->get_no_of_vehicles();
	}

	for (int i = 0; i < in_NSegs; i++)
	{
		int previous = i - 1, next = i + 1;
		if (i == 0)
		{
			segments[i]->set_get_previous(NULL);
			segments[i]->set_get_next(segments[next]);
		}
		else if (i == (in_NSegs-1))
		{
			segments[i]->set_get_previous(segments[previous]);
			segments[i]->set_get_next(NULL);
		}
		else
		{
			segments[i]->set_get_previous(segments[previous]);
			segments[i]->set_get_next(segments[next]);
		}
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
		no_of_vehicles += segments[i]->operate();
	}
}
