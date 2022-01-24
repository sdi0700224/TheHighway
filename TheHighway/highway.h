#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "segment.h"
#include "debug.h"

using namespace std;

class highway
{
	const int NSegs;
	const int K;
	const int Percent;
	const int SegmentCapacity;
	vector <segment*> segments;
	int no_of_vehicles;

	void connect_segments();

public:

	highway(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity);
	highway(const highway& in_object);
	~highway();

	void operate();

};

