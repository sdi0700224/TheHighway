#pragma once
#include <iostream>
#include <queue>
#include "entrance.h"
#include "debug.h"


using namespace std;


class segment
{
	int NSegs;
	int K;
	const int Percent;
	const int Possition;
	const int Segment_capacity;
	

	entrance segment_entrance;
	vector <vehicle*> vehicles;
	segment* previousSegment;
	segment* nextSegment;	


public:

	segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_Segment_capacity, const int in_possition, segment* in_previous, segment* in_next);
	segment(const segment& in_object);
	~segment();

	void enter();
	void exit();
	void pass();
	int get_no_of_vehicles();
	int operate();

	segment* set_get_previous(segment* in_previous = NULL);
	segment* set_get_next(segment* in_next = NULL);
};

