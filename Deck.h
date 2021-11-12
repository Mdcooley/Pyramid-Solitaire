#pragma once
#include "DeckNode.h"

class Deck
{
	public:

		/*
		Name: Deck

		Parameters: None

		Return: N/A

		Purpose: Constructor for the Deck class
		*/
		Deck();

		/*
		Name: Deck

		Parameters: Deck &copy, deck to be copied

		Return: N/A

		Purpose: Copy constructor for deck.
				 This does preform a shallow copy, but only because a deep copy is not needed in this program
		*/
		Deck(const Deck &copy);

		/*
		Name: operator=

		Parameters: Deck &rhs, deck on the right hand side of the equals sign

		Return: A reference to a deck

		Purpose: Defines the behavior of the = operator for the Deck class
				 This does preform a shallow copy, but only because a deep copy is not needed in this program
		*/
		Deck & operator=(const Deck &rhs);

		/*
		Name: Deck

		Parameters: DeckNode * node, desired top node of the list

		Return: N/A

		Purpose: Overloaded constructor for the Deck class, sets the first node immediatley
		*/
		Deck(DeckNode * node);

		/*
		Name: ~Deck

		Parameters: None

		Return: N/A

		Purpose: Deconstructor for the Deck class, deletes all nodes in the stack to prevent memory leaks
		*/
		~Deck();

		/*
		Name: Push

		Parameters: DeckNode * card, node to be placed on the stack

		Return: None

		Purpose: Pushes a new node onto the top of the stack
		*/
		void Push(DeckNode * card);

		/*
		Name: PlaceOnBottom

		Parameters: DeckNode * card, node to be placed on the stack

		Return: None

		Purpose: Places a new node onto the bottom of the stack (which means it's not technically a stack then)
		*/
		void PlaceOnBottom(DeckNode * card);

		/*
		Name: IsEmpty

		Parameters: None

		Return: bool, true if the stack is empty and false otherwise

		Purpose: Determine if the stack containes any nodes and returns an appropriate value
		*/
		bool IsEmpty();

		/*
		Name: Pop

		Parameters: None

		Return: DeckNode *, the (former) top node of the stack

		Purpose: Removes the top node of the stack, and then returns it
		*/
		DeckNode * Pop();

		/*
		Name: Peek

		Parameters: None

		Return: DeckNode *, the (current) top node of the stack

		Purpose: Returns the top node of the stack without removing it
		*/
		DeckNode * Peek();

		/*
		Name: GetBottom

		Parameters: None

		Return: DeckNode *, the (current) bottom node of the stack

		Purpose: Returns the bottom node of the stack without removing it
		*/
		DeckNode * GetBottom();

	private:
		DeckNode * top; //Pointer to the top node in the list
		DeckNode * bottom; //Pointer to the bottom node in the list
};