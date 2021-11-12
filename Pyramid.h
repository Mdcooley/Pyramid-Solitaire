#pragma once
#include "PyramidNode.h"
#include "Deck.h"

class Pyramid
{
	public:

		/*
		Name: Pyramid

		Parameters: None

		Return: N/A

		Purpose: Default constructor for the Pyramid class
		*/
		Pyramid();

		/*
		Name: Pyramid

		Parameters: const Pyramid &copy, Pyramid to be copied

		Return: N/A

		Purpose: Copy constructor for the Pyramid class
		*/
		Pyramid(const Pyramid &copy);

		/*
		Name: ~Pyramid

		Parameters: None

		Return: N/A

		Purpose: Destructor for the Pyramid class
		*/
		~Pyramid();

		/*
		Name: operator=

		Parameters: const Pyramid &rhs, object of the right side of the equals sign

		Return: A reference to a Pyramid object

		Purpose: Defines the behavior of the = operator with the Pyramid class
		*/
		Pyramid & operator=(const Pyramid &rhs);

		/*
		Name: Create

		Parameters: Deck &deck, a deck of cards

		Return: None

		Purpose: Deals out the Pyramid from the deck
		*/
		void Create(Deck &deck);

		/*
		Name: HasCard

		Parameters: PyramidNode * node, PyramidNode to check 
					Card card, Card to be checked for

		Return: bool, true if the Pyramid contains the secified card

		Purpose: Recursive function the check if the Pyramid has a card
		*/
		bool HasCard(PyramidNode * node, Card card);

		/*
		Name: RemoveCard

		Parameters: PyramidNode * node, PyramidNode to check
					Card card, Card to be removed

		Return: None

		Purpose: Recursive function to remove a specific card from the Pyramid
		*/
		void RemoveCard(PyramidNode * node, Card card);

		/*
		Name: IsEmpty

		Parameters: None

		Return: bool, true if no card remain in the Pyramid

		Purpose: Determines if the pyramid has all card removed (i.e. victory has been achieved)
		*/
		bool IsEmpty();

		/*
		Name: Display

		Parameters: None

		Return: None

		Purpose: Displays the Pyramid to the console
		*/
		void Display();

		/*
		Name: Cleanup

		Parameters: PyramidNode * node, Top node of the pyramid

		Return: None

		Purpose: Deletes all nodes from the pyramid to prevent memory leaks
		*/
		void Cleanup(PyramidNode * node);

		/*
		Name: GetHead

		Parameters: None

		Return: A pointer to a PyramidNode object

		Purpose: Returns a pointer to the head of they Pyramid
		*/
		PyramidNode * GetHead();

	private:
		PyramidNode * head;//Pointer to the top node of the pyramid
};