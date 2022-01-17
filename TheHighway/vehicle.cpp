#include "vehicle.h"

vehicle::vehicle(const int in_index, const int in_segment):
	exit_node_index(in_index), current_segment_index(), is_ready_to_exit(false)
{
}

void vehicle::set_segment(const int index)
{
	current_segment_index = index;
}
