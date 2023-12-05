#pragma once
class RangeHolder
{
public:
	RangeHolder(long long source, long long destination, long long range);
	bool inRange(long long input);
	long long map(long long input);

private:
	long long start;
	long long end;
	long long moveValue;
};

