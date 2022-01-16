#pragma once
#include <iostream>
#include <queue>
#include "vehicle.h"

using namespace std;

class toll
{
	int K;
	const int numberOfVehicles;
	queue <vehicle*> waiting_vehicles;

	void add();
	void substract();

public:

	toll(const int in_K, const int in_numberOfVehicles);

	void reload();
	vehicle* recieve_vehicle();



};

