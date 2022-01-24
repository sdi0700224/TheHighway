#include "vehicle.h"

vehicle::vehicle(const int in_index, const int in_segment, const bool in_is_ready):
	destination_node_index(in_index), current_segment_index(in_segment), is_ready_to_exit(in_is_ready){}

int vehicle::get_destination() const
{
	return destination_node_index;
}

void vehicle::set_possition(const int in_index)
{
	current_segment_index = in_index;
}

bool vehicle::get_is_ready() const
{
	return is_ready_to_exit;
}

void vehicle::set_is_ready(const bool in_is_ready)
{
	is_ready_to_exit = in_is_ready;
}
