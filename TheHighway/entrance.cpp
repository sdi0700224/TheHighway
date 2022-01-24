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

entrance::entrance(const int in_possition, const int in_toll_number, const int in_digital_toll_number, const int in_K, const int in_segment_capacity, const int in_NSegs):
	Segment_capacity(in_segment_capacity), Possition(in_possition), NSegs(in_NSegs)
{
	for (int i = 0; i < in_toll_number; i++)
	{
		collector_tolls.push_back(new collector_toll(in_K, in_NSegs));
	}

	for (int i = 0; i < in_digital_toll_number; i++)
	{
		digital_tolls.push_back(new digital_toll(in_K, in_NSegs));
	}
}

entrance::entrance(const entrance& in_object):
	Segment_capacity(in_object.Segment_capacity), Possition(in_object.Possition), NSegs(in_object.NSegs)
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

void entrance::operate(vector<vehicle*> &vehicles)
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
	reinit_all();
}
