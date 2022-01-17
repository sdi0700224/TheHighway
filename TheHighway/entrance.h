#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "toll.h"
#include "digital_toll.h"

using namespace std;

class entrance
{
	const int segment_capacity;
	const int nodeIndex;
	const int NSegs;
	vector <toll*> tolls;
	vector <digital_toll*> digital_tolls;

	void reinit_all();

public:

	entrance(const int in_index, const int toll_number, const int digital_toll_number, const int in_K, const int segment_capacity, const int in_NSegs);

	void operate(vector <vehicle*> vehicles);



};

