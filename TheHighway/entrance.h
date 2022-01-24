#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "toll.h"
#include "digital_toll.h"
#include "collector_toll.h"	
#include "debug.h"


using namespace std;

class entrance
{
	const int Segment_capacity;
	const int Possition;
	const int NSegs;
	int K;
	vector <collector_toll*> collector_tolls;
	vector <digital_toll*> digital_tolls;

	void reinit_all();
	bool max_is_reached();

public:

	entrance(const int in_possition, const int toll_number, const int digital_toll_number, const int in_K, const int segment_capacity, const int in_NSegs);
	entrance(const entrance& in_object);
	~entrance();

	void operate(vector <vehicle*> &vehicles);
	int get_K() const;



};

