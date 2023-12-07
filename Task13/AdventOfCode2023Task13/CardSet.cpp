#include "CardSet.h"

#include <algorithm>
#include <vector>

CardSet::CardSet(std::string value)
{
	for (int i = 0; i < 5; i++) {
		switch (value[i])
		{
		case 'A':
			cards[i] = 14;
			break;
		case 'K':
			cards[i] = 13;
			break;
		case 'Q':
			cards[i] = 12;
			break;
		case 'J':
			cards[i] = 11;
			break;
		case 'T':
			cards[i] = 10;
			break;
		default:
			cards[i] = value[i] - '0';
			break;
		}
	}
	setValue = findSetValue();
}

int CardSet::findSetValue() const
{
	std::array<int, 5> workArray = cards;
	std::sort(workArray.begin(), workArray.end());
	std::vector<int> doubles;
	if (workArray[0] == workArray[1]) {
		if (workArray[0] == workArray[2]) {
			if (workArray[0] == workArray[3]) {
				if (workArray[0] == workArray[4]) {
					return 7;
				}
				return 6;
			}
			if (workArray[3] == workArray[4]) {
				return 5;
			}
			return 4;
		}
		if (workArray[2] == workArray[3]) {
			if (workArray[2] == workArray[4]) {
				return 5;
			}
			return 3;
		}
		if (workArray[3] == workArray[4]) {
			return 3;
		}
		return 2;
	}
	if (workArray[1] == workArray[2]) {
		if (workArray[1] == workArray[3]) {
			if (workArray[1] == workArray[4]) {
				return 6;
			}
			return 4;
		}
		if (workArray[3] == workArray[4]) {
			return 3;
		}
		return 2;
	}
	if (workArray[2] == workArray[3]) {
		if (workArray[2] == workArray[4]) {
			return 4;
		}
		return 2;
	}
	if (workArray[3] == workArray[4]) {
		return 2;
	}
	return 1;
}
