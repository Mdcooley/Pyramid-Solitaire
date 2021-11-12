#pragma once
#include "Card.h"
#include "DeckNode.h"

class PyramidNode
{
	public:

		/*
		Name: PyramidNode

		Parameters: None

		Return: N/A

		Purpose: Default PyramidNode constructor
		*/
		PyramidNode();

		/*
		Name: PyramidNode

		Parameters: const PyramidNode &copy, PyramidNode to be copied

		Return: N/A

		Purpose: Copy constructor for PyramidNode
		*/
		PyramidNode(const PyramidNode &copy);

		/*
		Name: PyramidNode

		Parameters: Card card

		Return: N/A

		Purpose: 1 arg constructor for PyramidNode, assigns the card on creation
		*/
		PyramidNode(Card card);

		/*
		Name: ~PyramidNode

		Parameters: None

		Return: N/A

		Purpose: Destructor for PyramidNode
		*/
		~PyramidNode();

		/*
		Name: operator=

		Parameters: const PyramidNode &rhs, PyramidNode on the right side of the equals

		Return: A reference to a PyramidNode object

		Purpose: Defines the behavior of the = sign with the PyramidNode class
		*/
		PyramidNode & operator=(const PyramidNode &rhs);

		/*
		Name: GetNext

		Parameters: None

		Return: A pointer to a PyramidNode object

		Purpose: Returns a pointer to the adjacent node in the pyramid
		*/
		PyramidNode * GetNext();

		/*
		Name: GetLeft

		Parameters: None

		Return: A pointer to a PyramidNode object

		Purpose: Returns a pointer to the nodes left child in the pyramid
		*/
		PyramidNode * GetLeft();

		/*
		Name: GetRight

		Parameters: None

		Return: A pointer to a PyramidNode object

		Purpose: Returns a pointer to the nodes right child in the pyramid
		*/
		PyramidNode * GetRight();

		/*
		Name: GetCard

		Parameters: None

		Return: A pointer to a Card object

		Purpose: Return a pointer to the Card stored in the node
		*/
		Card * GetCard();

		/*
		Name: SetNext

		Parameters: PyramidNode * next, pointer to the adjacent node in the pyramid

		Return: None

		Purpose: Sets the next value of the current node
		*/
		void SetNext(PyramidNode * next);

		/*
		Name: SetLeft

		Parameters: PyramidNode * left, pointer to the nodes left child

		Return: None

		Purpose: Sets the left child of the current node
		*/
		void SetLeft(PyramidNode * left);

		/*
		Name: SetRight

		Parameters: PyramidNode * right, pointer to the nodes right child

		Return: None

		Purpose: Sets the right child of the current node
		*/
		void SetRight(PyramidNode * right);

		/*
		Name: SetCard

		Parameters: Card card, the card contained in the node

		Return: None

		Purpose: Sets the card contained in the current node
		*/
		void SetCard(Card card);

		/*
		Name: HasNoChildren

		Parameters: None

		Return: bool, true if the current node has no children

		Purpose: Determine if a node in the pyramid has any valid children
		*/
		bool HasNoChildren();

	private:
		PyramidNode * next;//pointer to the adjacent node
		PyramidNode * left;//pointer to the left hand child node
		PyramidNode * right;//pointer to the right hand child node
		Card card;//Card contained in the node
};
