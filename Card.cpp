#include "Card.h"

/*
Name: Card

Parameters: None

Return: N/A

Purpose: Constructor for the card class
*/
Card::Card()
{
	Card::rank = 1;
	Card::suit = 0;
}

/*
Name: Card

Parameters: int num, number between 0 and 51

Return: None

Purpose: Overloaded constructor for card, sets rank and suit depending on num
*/
Card::Card(int num)
{
	if (num < 0)
	{
		this->rank = num;
		this->suit = num;
	}
	else
	{
		this->rank = (num % 13) + 1;
		this->suit = num / 13;
	}
}

/*
Name: Card

Parameters: string str, input string to be converted into a card

Retrun: N/A

Purpose: Converts an string input into a card
*/
Card::Card(string str)
{
	char cRank[1], cSuit[1];

	if (str.length() == 2)
	{
		cRank[0] = str[0];
		cSuit[0] = str[1];

		switch (cRank[0])
		{
			case 'A':
			case 'a':
			{
				this->rank = ACE;
				break;
			}
			case 'J':
			case 'j':
			{
				this->rank = JACK;
				break;
			}
			case 'Q':
			case 'q':
			{
				this->rank = QUEEN;
				break;
			}
			case 'K':
			case 'k':
			{
				this->rank = KING;
				break;
			}
			default:
			{
				this->rank = atoi(cRank);
			}
		}

		switch (cSuit[0])
		{
			case 'H':
			case 'h':
			{
				this->suit = HEARTS;
				break;
			}
			case 'C':
			case 'c':
			{
				this->suit = CLUBS;
				break;
			}
			case 'D':
			case 'd':
			{
				this->suit = DIAMONDS;
				break;
			}
			case 'S':
			case 's':
			{
				this->suit = SPADES;
			}
		}
	}
	else if (str.length() == 3)
	{
		cSuit[0] = str[2];

		this->rank = TEN;

		switch (cSuit[0])
		{
		case 'H':
		case 'h':
		{
			this->suit = HEARTS;
			break;
		}
		case 'C':
		case 'c':
		{
			this->suit = CLUBS;
			break;
		}
		case 'D':
		case 'd':
		{
			this->suit = DIAMONDS;
			break;
		}
		case 'S':
		case 's':
		{
			this->suit = SPADES;
		}
		}
	}
	else
	{
		this->rank = ACE;
		this->suit = HEARTS;
	}
}

/*
Name: Card

Parameters: Card &copy, card to be copied

Return: N/A

Purpose: Copy constructor for card
*/
Card::Card(const Card &copy)
{
	this->rank = copy.rank;
	this->suit = copy.suit;
}

/*
Name: ~Card

Parameters: None

Return: N/A

Purpose: Deconstructor for the card class
*/
Card::~Card()
{

}

/*
Name: GetRank

Parameters: None

Return: int, rank of the card

Purpose: returns the rank of the card
*/
int Card::GetRank()
{
	return Card::rank;
}

/*
Name: GetSuit

Parameters: None

Return: int, suit of the card

Purpose: returns the suit of the card
*/
int Card::GetSuit()
{
	return Card::suit;
}

/*
Name: SetRank

Parameters: int rank, desired rank of the card, between 0 and 12 (ACE through KING)

Return: None

Purpose: Sets the rank of the card to a given value
*/
void Card::SetRank(int rank)
{
	this->rank = rank;
}

/*
Name: SetSuit

Parameters: int suit, desired suit of the card, between 0 and 3 (HEARTS through SPADES)

Return: None

Purpose: Sets the suit of the card to a given value
*/
void Card::SetSuit(int suit)
{
	this->suit = suit;
}

/*
Name: PrintData

Parameters: None

Return: None

Purpose: Prints out both the rank and suit (using the unicode symbols) of the card
*/
void Card::PrintData()
{
	switch (Card::rank)
	{
		case KING:
		{
			cout << "K";
			break;
		}
		case QUEEN:
		{
			cout << "Q";
			break;
		}
		case JACK:
		{
			cout << "J";
			break;
		}
		case ACE:
		{
			cout << "A";
			break;
		}
		default:
		{
			cout << this->rank;
		}
	}
	
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (Card::suit)
	{
		case HEARTS:
			wcout << L"\u2665";
			break;
		case CLUBS:
			wcout << L"\u2663";
			break;
		case DIAMONDS:
			wcout << L"\u2666";
			break;
		case SPADES:
			wcout << L"\u2660";
			break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
}

/*
Name: IsNull

Parameters: None

Return: bool, true if the card is invalid

Purpose: Determine if a card contains a valid rank and suit
*/
bool Card::IsNull()
{
	return (this->rank < 0 && this->suit < 0);
}

/*
Name: operator=

Parameters: Card card2, what you would like to set it equal to

Return: A reference to a card

Purpose: Defines the behavior of the equals operator with the card class
*/
Card & Card::operator=(const Card &rhs)
{
	Card::rank = rhs.rank;
	Card::suit = rhs.suit;
	return *this;
}

/*
Name: IsEquals

Parameters: Card & card2, card to be compared

Return: bool, true if the two cards are equivalent

Purpose: Determine if two cards are equivalent
*/
bool Card::IsEqual(Card & card2)
{
	bool temp = false;
	
	if (this->rank == card2.rank && this->suit == card2.suit)
	{
		temp = true;
	}

	return temp;
}