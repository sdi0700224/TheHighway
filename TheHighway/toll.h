#pragma once
#include <iostream>
#include <queue>
#include "vehicle.h"
#include "debug.h"

class entrance;

using namespace std;

class toll
{
protected:

	const entrance* belonging_node;
	int counter;
	const int NSegs;
	deque <vehicle*> waiting_vehicles;

	void add();
	void substract();

public:

	toll(const entrance* in_belonging_node, const int in_NSegs);
	toll(const toll& in_object);
	virtual ~toll();

	virtual void reinit() = 0;
	vehicle* recieve_vehicle();
	virtual bool limit_is_reached() const = 0;
	bool toll_is_empty() const;
};