#pragma once

#include <vector>

#include "RangeHolder.h"

class RangedMapper
{
public:
	RangedMapper();
	void insert(long long source, long long destination, long long range);
	long long map(long long input);

private:
	std::vector<RangeHolder> ranges;
};

