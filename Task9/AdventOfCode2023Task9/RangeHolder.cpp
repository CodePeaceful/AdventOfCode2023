#include "RangeHolder.h"

RangeHolder::RangeHolder(long long source, long long destination, long long range) {
	start = source;
	end = source + range - 1;
	moveValue = destination - source;
}

bool RangeHolder::inRange(long long input) {
	if (input >= start && input <= end)
		return true;
	return false;
}

long long RangeHolder::map(long long input)
{
	return input + moveValue;
}
