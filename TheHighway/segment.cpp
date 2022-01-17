#include "segment.h"
#include "toll.h"
#include "digital_toll.h"


segment::segment(const int in_NSegs, const int in_K, const int in_Percent, const int in_SegmentCapacity, const int in_possition, segment* in_previous, segment* in_next) :
	NSegs(in_NSegs), K(in_K), Percent(in_Percent), Possition(in_possition), entrance(in_possition, rand() % 5, rand() % 5, in_K, in_SegmentCapacity, in_NSegs), SegmentCapacity(in_SegmentCapacity), previousSegment(in_previous), nextSegment(in_next)
{

}

void segment::operate()
{
	//Change vehicle index before sent


}
