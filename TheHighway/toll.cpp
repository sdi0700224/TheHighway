#include "toll.h"

toll::toll(const int in_K, const int in_NSegs):
	K(in_K), counter(0), NSegs(in_NSegs)
{
	reinit();
}

toll::toll(const toll& in_object) :
	K(in_object.K), counter(in_object.counter), NSegs(in_object.NSegs) 
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

void toll::reinit()
{
	counter = 0;
	int vehicles_to_wait = rand() % ((2 * K) + 1);
	while (waiting_vehicles.size() < vehicles_to_wait)
	{
		add();
	}
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
