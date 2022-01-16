#include "toll.h"

toll::toll(const int in_K, const int in_numberOfVehicles) :
	K(in_K), numberOfVehicles(in_numberOfVehicles)
{
	for (int i = 0; i < in_numberOfVehicles; i++)
	{
		add();
	}
}

void toll::add()
{
	waiting_vehicles.push(new vehicle());
}

void toll::substract()
{
	waiting_vehicles.pop();
}

void toll::reload()
{
	while (waiting_vehicles.size() < numberOfVehicles)
	{
		add();
	}
}

vehicle* toll::recieve_vehicle()
{
	if (waiting_vehicles.empty())
	{
		return NULL;
	}
	vehicle* vehicle_to_return = waiting_vehicles.front();
	substract();
	return vehicle_to_return;
}
