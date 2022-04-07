#include <iostream>
#include <math.h>



#include <iostream>

class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	
	enum suit { CLUBS, BUBNY, HEARTS, PIKY };

	Card(rank r = ACE, suit p = PIKY, bool ifu = true) : m_Rank(r), m_Suit(p), m_IsFaceUp(ifu) { }

	int GetValue();
	void Flip();

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
int Card::GetValue()
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !m_IsFaceUp;
}
