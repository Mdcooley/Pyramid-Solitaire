#pragma once
#include <io.h>
#include <fcntl.h>
#include <string>
using std::string;
#include <iostream>
using std::wcout;
using std::cout;
using std::endl;

class Card
{
	//Possible ranks for the cards
	enum Ranks { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

	//Possible suits for the cards
	enum Suits { HEARTS, CLUBS, DIAMONDS, SPADES };

	public:
		/*
		Name: Card

		Parameters: None

		Return: N/A

		Purpose: Constructor for the card class
		*/
		Card();

		/*
		Name: Card

		Parameters: int num, number between 0 and 51

		Return: None

		Purpose: Overloaded constructor for card, sets rank and suit depending on num
		*/
		Card(int num);

		/*
		Name: Card

		Parameters: string str, input string to be converted into a card

		Retrun: N/A

		Purpose: Converts an string input into a card
		*/
		Card(string str);

		/*
		Name: Card

		Parameters: Card &copy, card to be copied

		Return: N/A

		Purpose: Copy constructor for card
		*/
		Card(const Card &copy);

		/*
		Name: ~Card

		Parameters: None

		Return: N/A

		Purpose: Deconstructor for the card class
		*/
		~Card();

		/*
		Name: GetRank

		Parameters: None

		Return: int, rank of the card

		Purpose: returns the rank of the card
		*/
		int GetRank();

		/*
		Name: GetSuit

		Parameters: None

		Return: int, suit of the card

		Purpose: returns the suit of the card
		*/
		int GetSuit();

		/*
		Name: SetRank

		Parameters: int rank, desired rank of the card, between 0 and 12 (ACE through KING)

		Return: None

		Purpose: Sets the rank of the card to a given value
		*/
		void SetRank(int rank);

		/*
		Name: SetSuit

		Parameters: int suit, desired suit of the card, between 0 and 3 (HEARTS through SPADES)

		Return: None

		Purpose: Sets the suit of the card to a given value
		*/
		void SetSuit(int suit);

		/*
		Name: PrintData

		Parameters: None

		Return: None

		Purpose: Prints out both the rank and suit (using the unicode symbols) of the card
		*/
		void PrintData();

		/*
		Name: IsNull

		Parameters: None

		Return: bool, true if the card is invalid

		Purpose: Determine if a card contains a valid rank and suit
		*/
		bool IsNull();

		/*
		Name: operator=

		Parameters: Card card2, what you would like to set it equal to

		Return: A reference to a card

		Purpose: Defines the behavior of the equals operator with the card class
		*/
		Card & operator=(const Card &card2);

		/*
		Name: IsEquals

		Parameters: Card & card2, card to be compared

		Return: bool, true if the two cards are equivalent

		Purpose: Determine if two cards are equivalent
		*/
		bool IsEqual(Card &card2);

	private:
		int rank; //Stores the rank of the card
		int suit; //Stores the suit of the card
};