#include "segment.h"
#include "toll.h"
#include "digital_toll.h"


void segment::get_ready_to_exit()
{
	int vehicles_to_get_ready_num = (double)(Percent / 100) * get_no_of_vehicles();

	for (int i = 0; i < vehicles_to_get_ready_num; i++)
	{
		if (!vehicles[i]->get_is_ready())
		{
			vehicles[i]->set_is_ready(true);
		}
		else
		{
			if (vehicles_to_get_ready_num < get_no_of_vehicles() - 1)
			{
				vehicles_to_get_ready_num++;
			}
		}
	}
}

segment::segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_Segment_capacity, const int in_possition, segment* in_previous, segment* in_next) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), Possition(in_possition), segment_entrance(in_possition, (rand() % 5) + 1, (rand() % 5) + 1, in_K, in_Segment_capacity, in_NSegs), Segment_capacity(in_Segment_capacity), previousSegment(in_previous), nextSegment(in_next)
{
	int initial_vehicles_number = rand() % (in_Segment_capacity + 1);
	for (int i = 0; i < initial_vehicles_number; i++)
	{
		bool is_ready = rand() % 2 == 0 ? true : false;
		vehicles.push_back(new vehicle(in_possition + (rand() % (in_NSegs -	in_possition)) + 1, in_possition, is_ready));
	}
}

segment::segment(const segment& in_object):
	NSegs(in_object.NSegs), K(in_object.K), Percent(in_object.Percent), Possition(in_object.Possition), segment_entrance(in_object.segment_entrance), Segment_capacity(in_object.Segment_capacity), previousSegment(in_object.previousSegment), nextSegment(in_object.nextSegment)
{
	for (int i = 0; i < in_object.vehicles.size(); i++)
	{
		vehicles.push_back(new vehicle(*(in_object.vehicles[i])));
	}
}

segment::~segment()
{
	for (int i = 0; i < vehicles.size(); i++)
	{
		delete vehicles[i];
	}
}

int segment::enter()
{
	return segment_entrance.operate(vehicles);
}

void segment::exit()
{
	for (vector<vehicle*>::iterator it = vehicles.begin(); it != vehicles.end();)
	{
		if ((*it)->get_destination() - 1 == Possition)
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
		if ((*it)->get_is_ready() && (*it)->get_destination() - 1 > Possition && nextSegment->get_no_of_vehicles() < nextSegment->Segment_capacity)
		{
			(*it)->set_possition(Possition + 1);
			(*it)->set_is_ready(false);
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
	return (int)vehicles.size();
}

int segment::operate()
{
	int cur_number_of_vehicles;

	cout << "\nSegment no: " << Possition + 1 << " is operating.." << endl;

	int starting_car_number = get_no_of_vehicles();

	cout << "Segment's no: " << Possition + 1 << " cars are exiting.." << endl;
	exit();

	cur_number_of_vehicles = get_no_of_vehicles();
	if (previousSegment != NULL)
	{
		cout << "Cars are entering to the Segment no: " << Possition + 1 << " from previous segment" << endl;
		previousSegment->pass();
	}
	int num_of_vihicles_passed_from_prev_seg = get_no_of_vehicles() - cur_number_of_vehicles;

	cout << "Cars are entering to the Segment no: " << Possition + 1 << " from tolls" << endl;

	cur_number_of_vehicles = get_no_of_vehicles();
	int waiting_num_of_vehicles = enter();
	int num_of_vihicles_entered_from_entrance = get_no_of_vehicles() - cur_number_of_vehicles;

	
	bool all_ok = true;
	if (num_of_vihicles_entered_from_entrance < waiting_num_of_vehicles)
	{
		cout << "Delays in the entrance of Node: " << Possition + 2 << endl;
		all_ok = false;
	}

	if (previousSegment != NULL && (num_of_vihicles_passed_from_prev_seg < previousSegment->get_ready_vehicles_num()))
	{
		cout << "Delays after Node: " << Possition + 2 << endl;
		all_ok = false;
	}

	if (all_ok)
	{
		cout << "Keep safety distance at segment after Node: " << Possition + 2 << endl;
	}
	get_ready_to_exit();
	return get_no_of_vehicles() - starting_car_number - num_of_vihicles_passed_from_prev_seg;
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

int segment::get_ready_vehicles_num() const
{
	int counter = 0;
	for (int i = 0; i < vehicles.size(); i++)
	{
		if (vehicles[i]->get_is_ready())
		{
			counter++;
		}
	}
	return counter;
}

bool segment::ready_vehicles_exist() const
{
	bool exist = false;

	for (int i = 0; i < vehicles.size(); i++)
	{
		exist |= vehicles[i]->get_is_ready();
	}
	return exist;
}
