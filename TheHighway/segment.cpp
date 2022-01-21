#include "segment.h"
#include "toll.h"
#include "digital_toll.h"


segment::segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_Segment_capacity, const int in_possition, segment* in_previous, segment* in_next) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), Possition(in_possition), segment_entrance(in_possition, rand() % 5, rand() % 5, in_K, in_Segment_capacity, in_NSegs), Segment_capacity(in_Segment_capacity), previousSegment(in_previous), nextSegment(in_next), vehicles(rand() % in_Segment_capacity)
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		vehicles[i] = new vehicle(rand() % in_NSegs, in_possition);
	}
}

segment::~segment()
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		delete vehicles[i];
	}
}

void segment::enter()
{
	segment_entrance.operate(vehicles);
}

void segment::exit()
{
	for (vector<vehicle*>::iterator it = vehicles.begin(); it != vehicles.end();)
	{
		if ((*it)->get_destination() == Possition)
		{
			delete *it;
			it = vehicles.erase(it);
		}
		else
		{
			it++;
		}
	}
}

void segment::pass()
{
	if (nextSegment == NULL)
	{
		return;
	}

	for (vector<vehicle*>::iterator it = vehicles.begin(); it != vehicles.end();)
	{
		if ((*it)->get_is_ready() && (*it)->get_destination() > Possition && nextSegment->get_no_of_vehicles() < nextSegment->Segment_capacity)
		{
			(*it)->set_segment(Possition + 1);
			nextSegment->vehicles.push_back(*it);
			it = vehicles.erase(it);
		}
		else
		{
			it++;
		}
	}
}

int segment::get_no_of_vehicles()
{
	return vehicles.size();
}

int segment::operate()
{
	int starting_car_number = get_no_of_vehicles();

	exit();

	if (previousSegment != NULL)
	{
		previousSegment->pass();
	}

	enter();

	int ending_car_number = get_no_of_vehicles();

	return ending_car_number - starting_car_number;
}

segment* segment::set_get_previous(segment* in_previous)
{
	if (in_previous != NULL)
	{
		return previousSegment = in_previous;
	}
	else
	{
		return previousSegment;
	}
}

segment* segment::set_get_next(segment* in_next)
{
	if (in_next != NULL)
	{
		return nextSegment = in_next;
	}
	else
	{
		return nextSegment;
	}
}
