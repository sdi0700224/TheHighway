#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "segment.h"

using namespace std;

class attiki_odos
{
	const int NSegs;
	vector <string> nodes;
	vector <segment> segments;

	attiki_odos(const int in_NSegs);

};

