#pragma once
#include <iostream>
#include <queue>
#include "entrance.h"

using namespace std;


class segment
{
	int NSegs;
	int K;
	const int Percent;
	const int Possition;
	const int SegmentCapacity;
	

	entrance entrance;
	vector <vehicle*> vehicles;
	segment* previousSegment;
	segment* nextSegment;
	


public:

	segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity, const int in_possition, segment* in_previous, segment* in_next);
	~segment();

	void enter();
	void exit();
	void pass();
	int get_no_of_vehicles();
	int operate();
};

