#pragma once
#include <iostream>

using namespace std;

class vehicle
{
	const int destination_node_index;
	int current_segment_index;
	bool is_ready_to_exit;

public:

	vehicle(const int in_index, const int in_segment);


	int get_destination() const;
	void set_segment(const int index);
	bool get_is_ready() const;
	void set_is_ready(const bool in_is_ready);
};

