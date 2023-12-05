#include "RangedMapper.h"

RangedMapper::RangedMapper()
{
}

void RangedMapper::insert(long long source, long long destination, long long range)
{
	RangeHolder holder(source, destination, range);
	ranges.push_back(holder);
}

long long RangedMapper::map(long long input)
{
	for (RangeHolder holder : ranges) {
		if (holder.inRange(input)) {
			return holder.map(input);
		}
	}
	return input;
}

