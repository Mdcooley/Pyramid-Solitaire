#pragma once
#include "Card.h"

class DeckNode
{
	public:

		/*
		Name: DeckNode

		Parameters: None

		Return: N/A

		Purpose: Constructor for the DeckNode class
		*/
		DeckNode();

		/*
		Name: DeckNode

		Parameters: DeckNode &copy, DeckNode to be copied

		Return: N/A

		Purpose: Copy constructor for DeckNode
		*/
		DeckNode(const DeckNode &copy);

		/*
		Name: DeckNode

		Parameters: Card card, card that the node will be representing

		Return: N/A

		Purpose: Overloaded constructor for the DeckNode class, assigns the card immediatley
		*/
		DeckNode(Card card);

		/*
		Name: ~DeckNode

		Parameters: None

		Return: N/A

		Purpose: Deconstructor for the DeckNode class
		*/
		~DeckNode();

		/*
		Name: GetPrevious

		Parameters: None

		Return: DeckNode *, pointer to the previous node in the list

		Purpose: Return a pointer to the previous node in the list
		*/
		DeckNode * GetPrevious();

		/*
		Name: GetNext

		Parameters: None

		Return: DeckNode *, pointer to the next node in the list

		Purpose: Return a pointer to the next node in the list
		*/
		DeckNode * GetNext();

		/*
		Name: GetCard

		Parameters: None

		Return: Card, the card that the node is storing

		Purpose: Returns the card that the node is storing
		*/
		Card GetCard();

		/*
		Name: SetPrevious

		Parameters: DeckNode * prev, pointer to another DeckNode object

		Return: None

		Purpose: Changes what the previous node being pointed to is
		*/
		void SetPrevious(DeckNode * prev);

		/*
		Name: SetNext

		Parameters: DeckNode * next, pointer to another DeckNode object

		Return: None

		Purpose: Changes what the next node being pointed to is
		*/
		void SetNext(DeckNode * next);

		/*
		Name: SetCard

		Parameters: Card card, card object to be stored in the node

		Return: None

		Purpose: Sets the value of the card being stored
		*/
		void SetCard(Card card);

		/*
		Name: operator=

		Parameters: DeckNode other, node to be copied

		Return: A reference to a deck node

		Purpose: Defines the behavior of the equals operator with the DeckNode class
		*/
		DeckNode & operator=(const DeckNode &other);

	private:
		DeckNode * prev; //Pointer to the previous node in the linked list (stack?)
		DeckNode * next; //Pointer to the next node in the linked list (stack?)
		Card card; //The card that the node is representing (Maybe should be a pointer?)
};