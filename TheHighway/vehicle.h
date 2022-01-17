#pragma once
#include <iostream>

using namespace std;

class vehicle
{
	const int exit_node_index;
	int current_segment_index;
	bool is_ready_to_exit;

public:

	vehicle(const int in_index, const int in_segment);

	void set_segment(const int index);
};

