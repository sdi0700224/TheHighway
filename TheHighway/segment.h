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
	

	entrance entrance;
	vector <vehicle*> vehicles; //ask for this
	const int SegmentCapacity;
	segment* previousSegment;
	segment* nextSegment;
	


public:

	segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity, const int in_possition, segment* in_previous, segment* in_next);

	void operate(); // Ask.
};

