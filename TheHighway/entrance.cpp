#include "entrance.h"

void entrance::reinit_all()
{
	for (int i = 0; i < tolls.size(); i++)
	{
		tolls[i]->reinit(); //reloads and make count 0
	}
	for (int i = 0; i < digital_tolls.size(); i++)
	{
		tolls[i]->reinit(); //reloads and make count 0
	}
}

entrance::entrance(const int in_index, const int in_toll_number, const int in_digital_toll_number, const int in_K, const int in_segment_capacity):
	segment_capacity(in_segment_capacity), nodeIndex(in_index), tolls(in_toll_number), digital_tolls(in_digital_toll_number)
{
}

void entrance::operate(queue<vehicle*> vehicles)
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

			vehicle* recieved = tolls[i]->recieve_vehicle();
			if (recieved != NULL)
			{
				vehicles.push(recieved);
				tolls_empty = false;
			}
		}

		for (int i = 0; i < digital_tolls.size(); i++)
		{
			if (vehicles.size() >= segment_capacity)
			{
				break;
			}

			vehicle* recieved = tolls[i]->recieve_vehicle();
			if (recieved != NULL)
			{
				vehicles.push(recieved);
				tolls_empty = false;
			}
		}
	}
	reinit_all();
}
