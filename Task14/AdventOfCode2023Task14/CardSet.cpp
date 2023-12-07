#include "CardSet.h"

#include <algorithm>
#include <vector>

enum Sets
{
	single = 1,
	pair,
	twopair,
	three,
	fullhouse,
	four,
	five
};

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
			cards[i] = 1;
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
	addJokers();
}

int CardSet::findSetValue() const
{
	std::array<int, 5> workArray = cards;
	std::sort(workArray.begin(), workArray.end());
	std::vector<int> doubles;
	if (workArray[0] == workArray[1] && workArray[0] != 1) {
		if (workArray[0] == workArray[2]) {
			if (workArray[0] == workArray[3]) {
				if (workArray[0] == workArray[4]) {
					return Sets::five;
				}
				return Sets::four;
			}
			if (workArray[3] == workArray[4] && workArray[3] != 1) {
				return Sets::fullhouse;
			}
			return Sets::three;
		}
		if (workArray[2] == workArray[3] && workArray[2] != 1) {
			if (workArray[2] == workArray[4]) {
				return Sets::fullhouse;
			}
			return Sets::twopair;
		}
		if (workArray[3] == workArray[4] && workArray[3] != 1) {
			return Sets::twopair;
		}
		return Sets::pair;
	}
	if (workArray[1] == workArray[2] && workArray[1] != 1) {
		if (workArray[1] == workArray[3]) {
			if (workArray[1] == workArray[4]) {
				return Sets::four;
			}
			return Sets::three;
		}
		if (workArray[3] == workArray[4] && workArray[3] != 1) {
			return Sets::twopair;
		}
		return Sets::pair;
	}
	if (workArray[2] == workArray[3] && workArray[2] != 1) {
		if (workArray[2] == workArray[4]) {
			return Sets::three;
		}
		return Sets::pair;
	}
	if (workArray[3] == workArray[4] && workArray[3] != 1) {
		return Sets::pair;
	}
	return Sets::single;
}

void CardSet::addJokers()
{
	int js = 0;
	for (int i : cards) {
		if (i == 1)
			js++;
	}
	if (js == 5 || js == 4) {
		setValue = Sets::five;
		return;
	}
	if (js == 3) {
		if (setValue == Sets::pair) {
			setValue = Sets::five;
			return;
		}
		if (setValue == Sets::single) {
			setValue = Sets::four;
			return;
		}
	}
	if (js == 2) {
		if (setValue == Sets::pair) {
			setValue = Sets::four;
			return;
		}
		if (setValue == Sets::three) {
			setValue = Sets::five;
			return;
		}
		if (setValue == Sets::single) {
			setValue = Sets::three;
			return;
		}
	}
	if (js == 1) {
		if (setValue == Sets::single) {
			setValue = Sets::pair;
			return;
		}
		if (setValue == Sets::pair) {
			setValue = Sets::three;
			return;
		}
		if (setValue == Sets::twopair) {
			setValue = Sets::fullhouse;
			return;
		}
		if (setValue == Sets::three) {
			setValue = Sets::four;
			return;
		}
		if (setValue == Sets::four) {
			setValue = Sets::five;
			return;
		}
	}
}


