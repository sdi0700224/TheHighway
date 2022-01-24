#pragma once
#include <iostream>
#include <queue>
#include "vehicle.h"
#include "debug.h"


using namespace std;

class toll
{
protected:

	int K;
	int counter;
	const int NSegs;
	deque <vehicle*> waiting_vehicles;

	void add();
	void substract();
	virtual bool limit_is_reached() = 0;

public:

	toll(const int in_K, const int in_NSegs);
	toll(const toll& in_object);
	virtual ~toll();

	virtual void reinit() = 0;
	virtual vehicle* recieve_vehicle();



};

