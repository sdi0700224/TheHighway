#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "segment.h"

using namespace std;

class attiki_odos
{
	const int NSegs;
	const int K;
	const int Percent;
	const int SegmentCapacity;
	vector <segment*> segments;
	int no_of_vehicles;

public:

	attiki_odos(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity);
	~attiki_odos();

	void operate();

};

