#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "segment.h"

using namespace std;

class attiki_odos
{
	const int NSegs;
	const int K;
	const int Percent;
	vector <segment> segments;
	int no_of_vehicles;

	attiki_odos(const int in_NSegs, const int in_K, const int in_Percent);

};

