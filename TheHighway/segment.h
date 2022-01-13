#pragma once
#include <iostream>

using namespace std;


class toll;

class segment
{
	int K;
	int index;
	int NSegs;

	toll* entrance_toll;
	toll* exit_toll;
};

