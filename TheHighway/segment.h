#pragma once
#include <iostream>
#include "toll.h"
#include "digital_toll.h"

using namespace std;

class segment
{
	int K;
	const int index;
	const int NSegs;

	toll* entrance_toll;
	toll* exit_toll;
};

