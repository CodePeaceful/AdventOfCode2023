#pragma once

#include <string>
#include <array>

class CardSet
{
public:
	CardSet(std::string value);
	std::weak_ordering operator<=>(const CardSet& that) const
	{
		if (std::weak_ordering cmp = setValue <=> that.setValue; cmp != 0)
			return cmp;
		if (std::weak_ordering cmp = cards[0] <=> that.cards[0]; cmp != 0)
			return cmp;
		if (std::weak_ordering cmp = cards[1] <=> that.cards[1]; cmp != 0)
			return cmp;
		if (std::weak_ordering cmp = cards[2] <=> that.cards[2]; cmp != 0)
			return cmp;
		if (std::weak_ordering cmp = cards[3] <=> that.cards[3]; cmp != 0)
			return cmp;
		if (std::weak_ordering cmp = cards[4] <=> that.cards[4]; cmp != 0)
			return cmp;

		std::strong_ordering  cmp = cards <=> that.cards;
		return cmp;
	}

private:
	int findSetValue() const;
	int setValue = 0; // readonly
	std::array<int, 5> cards; // readonly
};

