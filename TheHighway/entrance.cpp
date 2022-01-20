#include "entrance.h"

void entrance::reinit_all()
{
	for (int i = 0; i < tolls.size(); i++)
	{
		tolls[i]->reinit(); //reloads and make count 0
	}
	for (int i = 0; i < digital_tolls.size(); i++)
	{
		digital_tolls[i]->reinit(); //reloads and make count 0
	}
}

entrance::entrance(const int in_index, const int in_toll_number, const int in_digital_toll_number, const int in_K, const int in_segment_capacity, const int in_NSegs):
	segment_capacity(in_segment_capacity), nodeIndex(in_index), tolls(in_toll_number), digital_tolls(in_digital_toll_number), NSegs(in_NSegs)
{
	for (int i = 0; i < tolls.size(); i++)
	{
		tolls[i] = new toll(in_K, rand() % in_segment_capacity, in_NSegs);
	}

	for (int i = 0; i < digital_tolls.size(); i++)
	{
		digital_tolls[i] = new digital_toll(in_K, rand() % in_segment_capacity, in_NSegs);
	}
}

entrance::~entrance()
{
	for (int i = 0; i < tolls.size(); i++)
	{
		delete tolls[i];
	}

	for (int i = 0; i < digital_tolls.size(); i++)
	{
		delete digital_tolls[i];
	}
}

void entrance::operate(vector<vehicle*> &vehicles)
{
	bool tolls_empty = false;
	while (vehicles.size() < segment_capacity && tolls_empty == false)
	{
		tolls_empty = true;
		for (int i = 0; i < tolls.size(); i++)
		{
			if (vehicles.size() >= segment_capacity)
			{
				break;
			}

			vehicle* recieved = tolls[i]->recieve_vehicle(); // Leak is here
			if (recieved != NULL)
			{
				recieved->set_segment(nodeIndex);
				vehicles.push_back(recieved);
				tolls_empty = false;
			}
		}

		for (int i = 0; i < digital_tolls.size(); i++)
		{
			if (vehicles.size() >= segment_capacity)
			{
				break;
			}

			vehicle* recieved = digital_tolls[i]->recieve_vehicle();
			if (recieved != NULL)
			{
				recieved->set_segment(nodeIndex);
				vehicles.push_back(recieved);
				tolls_empty = false;
			}
		}
	}
	reinit_all();
}
