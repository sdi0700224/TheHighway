#include "toll.h"

toll::toll(const int in_K, const int in_numberOfVehicles, const int in_NSegs) :
	K(in_K), counter(0), numberOfVehicles(in_numberOfVehicles), NSegs(in_NSegs)
{
	for (int i = 0; i < in_numberOfVehicles; i++)
	{
		add();
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
	waiting_vehicles.push(new vehicle(rand() % NSegs, -1));
}

void toll::substract()
{
	waiting_vehicles.pop();
}

bool toll::limit_is_reached()
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

void toll::reinit()
{
	counter = 0;
	while (waiting_vehicles.size() < numberOfVehicles)
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
