#include "attiki_odos.h"

attiki_odos::attiki_odos(const int in_NSegs, const int in_K, const int in_Percent) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), segments(in_NSegs), no_of_vehicles(in_NSegs*in_K)
{
	cout << "Highway operating..\n";
}
