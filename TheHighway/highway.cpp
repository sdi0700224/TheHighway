#include "highway.h"

highway::highway(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), no_of_vehicles(0), SegmentCapacity(in_SegmentCapacity)
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

highway::highway(const highway& in_object):
	NSegs(in_object.NSegs), K(in_object.K), Percent(in_object.Percent), SegmentCapacity(in_object.SegmentCapacity), no_of_vehicles(in_object.no_of_vehicles)
{
	for (int i = 0; i < in_object.segments.size(); i++)
	{
		segments.push_back(new segment(*(in_object.segments[i])));
	}

	for (int i = 0; i < in_object.segments.size(); i++)
	{
		int previous = i - 1, next = i + 1;
		if (i == 0)
		{
			segments[i]->set_get_previous(NULL);
			segments[i]->set_get_next(segments[next]);
		}
		else if (i == (in_object.segments.size() - 1))
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
}

highway::~highway()
{
	for (int i = 0; i < segments.size(); i++)
	{
		delete segments[i];
	}
}

void highway::operate()
{
	for (int i = (int)segments.size() - 1; i >= 0; i--)
	{
		no_of_vehicles += segments[i]->operate();
	}
}
