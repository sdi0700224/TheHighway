#include "entrance.h"

void entrance::reinit_all()
{
	for (int i = 0; i < collector_tolls.size(); i++)
	{
		collector_tolls[i]->reinit();
	}
	for (int i = 0; i < digital_tolls.size(); i++)
	{
		digital_tolls[i]->reinit();
	}
}

bool entrance::max_is_reached()
{
	bool is_reached = true;
	for (int i = 0; i < collector_tolls.size(); i++)
	{
		is_reached &= collector_tolls[i]->limit_is_reached();
	}
	for (int i = 0; i < digital_tolls.size(); i++)
	{
		is_reached &= digital_tolls[i]->limit_is_reached();
	}
	return is_reached; //Return true if everything is true
}

entrance::entrance(const int in_possition, const int in_toll_number, const int in_digital_toll_number, const int in_K, const int in_segment_capacity, const int in_NSegs):
	Segment_capacity(in_segment_capacity), Possition(in_possition), NSegs(in_NSegs), K(in_K)
{
	for (int i = 0; i < in_toll_number; i++)
	{
		collector_tolls.push_back(new collector_toll(this, in_NSegs));
	}

	for (int i = 0; i < in_digital_toll_number; i++)
	{
		digital_tolls.push_back(new digital_toll(this, in_NSegs));
	}
}

entrance::entrance(const entrance& in_object):
	Segment_capacity(in_object.Segment_capacity), Possition(in_object.Possition), NSegs(in_object.NSegs), K(in_object.K)
{
	for (int i = 0; i < collector_tolls.size(); i++)
	{
		collector_tolls.push_back(new collector_toll(*(in_object.collector_tolls[i])));
	}

	for (int i = 0; i < digital_tolls.size(); i++)
	{
		digital_tolls.push_back(new digital_toll(*(in_object.digital_tolls[i])));
	}
}

entrance::~entrance()
{
	for (int i = 0; i < collector_tolls.size(); i++)
	{
		delete collector_tolls[i];
	}

	for (int i = 0; i < digital_tolls.size(); i++)
	{
		delete digital_tolls[i];
	}
}

int entrance::operate(vector<vehicle*> &vehicles)
{
	bool tolls_empty = false;
	while (vehicles.size() < Segment_capacity && tolls_empty == false)
	{
		tolls_empty = true;
		for (int i = 0; i < collector_tolls.size(); i++)
		{
			if (vehicles.size() >= Segment_capacity)
			{
				break;
			}

			vehicle* recieved = collector_tolls[i]->recieve_vehicle();
			if (recieved != NULL)
			{
				recieved->set_possition(Possition);
				vehicles.push_back(recieved);
				tolls_empty = false;
			}
		}

		for (int i = 0; i < digital_tolls.size(); i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (vehicles.size() >= Segment_capacity)
				{
					break;
				}

				vehicle* recieved = digital_tolls[i]->recieve_vehicle();
				if (recieved != NULL)
				{
					recieved->set_possition(Possition);
					vehicles.push_back(recieved);
					tolls_empty = false;
				}
			}
		}
	}
	if (max_is_reached())
	{
		increase_limit();
	}
	else
	{
		decrease_limit();
	}
	int cur_num_of_vehicles = get_num_of_vehicles();
	reinit_all();
	return cur_num_of_vehicles;
}

int entrance::get_K() const
{
	return K;
}

void entrance::increase_limit()
{
	K++;
}

void entrance::decrease_limit()
{
	if (K > 1)
	{
		K--;
	}
}

int entrance::get_num_of_vehicles() const
{
	return collector_tolls.size() + digital_tolls.size();
}

bool entrance::is_empty() const
{
	bool is_empty = true;
	for (int i = 0; i < collector_tolls.size(); i++)
	{
		is_empty &= collector_tolls[i]->toll_is_empty();		
	}
	for (int i = 0; i < digital_tolls.size(); i++)
	{
		is_empty &= digital_tolls[i]->toll_is_empty();
	}
	return is_empty;
}
