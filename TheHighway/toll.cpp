#include "toll.h"
#include "entrance.h"

toll::toll(const entrance* in_belonging_node, const int in_NSegs):
	belonging_node(in_belonging_node), counter(0), NSegs(in_NSegs){}

toll::toll(const toll& in_object) :
	belonging_node(in_object.belonging_node), counter(in_object.counter), NSegs(in_object.NSegs)
{
	for (int i = 0; i < in_object.waiting_vehicles.size(); i++)
	{
		waiting_vehicles.push_back(new vehicle(*(in_object.waiting_vehicles[i])));
	}
}

toll::~toll()
{
	while(!waiting_vehicles.empty())
	{
		delete waiting_vehicles.front();
		substract();
	}
}

void toll::add()
{
	waiting_vehicles.push_back(new vehicle(rand() % NSegs, -1));
}

void toll::substract()
{
	waiting_vehicles.pop_front();
}

vehicle* toll::recieve_vehicle()
{
	if (waiting_vehicles.empty())
	{
		cout << "No cars are waiting on this toll.." << endl;
		return NULL;
	}
	if (!limit_is_reached())
	{
		vehicle* vehicle_to_return = waiting_vehicles.front();
		substract();
		counter++;
		return vehicle_to_return;
	}
	else
	{
		cout << "Toll limit has been reached for this operation cycle.." << endl;
		return NULL;
	}
}

void toll::increase_limit()
{
	
}

void toll::decrease_limit()
{
	if (belonging_node->get_K() > 1)
	{
		
	}
}
