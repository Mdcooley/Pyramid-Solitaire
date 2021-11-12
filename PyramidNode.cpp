#include "PyramidNode.h"

/*
Name: PyramidNode

Parameters: None

Return: N/A

Purpose: Default PyramidNode constructor
*/
PyramidNode::PyramidNode()
{
	this->next = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

/*
Name: PyramidNode

Parameters: const PyramidNode &copy, PyramidNode to be copied

Return: N/A

Purpose: Copy constructor for PyramidNode
*/
PyramidNode::PyramidNode(const PyramidNode & copy)
{
	this->next = copy.next;
	this->left = copy.left;
	this->right = copy.right;
	this->card = copy.card;
}

/*
Name: PyramidNode

Parameters: Card card

Return: N/A

Purpose: 1 arg constructor for PyramidNode, assigns the card on creation
*/
PyramidNode::PyramidNode(Card card)
{
	this->next = nullptr;
	this->left = nullptr;
	this->right = nullptr;
	this->card = card;
}

/*
Name: ~PyramidNode

Parameters: None

Return: N/A

Purpose: Destructor for PyramidNode
*/
PyramidNode::~PyramidNode()
{
	//this->left = nullptr;
	//this->next = nullptr;
	//this->right = nullptr;
}

/*
Name: operator=

Parameters: const PyramidNode &rhs, PyramidNode on the right side of the equals

Return: A reference to a PyramidNode object

Purpose: Defines the behavior of the = sign with the PyramidNode class
*/
PyramidNode & PyramidNode::operator=(const PyramidNode & rhs)
{
	this->next = rhs.next;
	this->left = rhs.left;
	this->right = rhs.right;
	this->card = rhs.card;

	return *this;
}

/*
Name: GetNext

Parameters: None

Return: A pointer to a PyramidNode object

Purpose: Returns a pointer to the adjacent node in the pyramid
*/
PyramidNode * PyramidNode::GetNext()
{
	return this->next;
}

/*
Name: GetLeft

Parameters: None

Return: A pointer to a PyramidNode object

Purpose: Returns a pointer to the nodes left child in the pyramid
*/
PyramidNode * PyramidNode::GetLeft()
{
	return this->left;
}

/*
Name: GetRight

Parameters: None

Return: A pointer to a PyramidNode object

Purpose: Returns a pointer to the nodes right child in the pyramid
*/
PyramidNode * PyramidNode::GetRight()
{
	return this->right;
}

/*
Name: GetCard

Parameters: None

Return: A pointer to a Card object

Purpose: Return a pointer to the Card stored in the node
*/
Card * PyramidNode::GetCard()
{
	return &this->card;
}

/*
Name: SetNext

Parameters: PyramidNode * next, pointer to the adjacent node in the pyramid

Return: None

Purpose: Sets the next value of the current node
*/
void PyramidNode::SetNext(PyramidNode * next)
{
	this->next = next;
}

/*
Name: SetLeft

Parameters: PyramidNode * left, pointer to the nodes left child

Return: None

Purpose: Sets the left child of the current node
*/
void PyramidNode::SetLeft(PyramidNode * left)
{
	this->left = left;
}

/*
Name: SetRight

Parameters: PyramidNode * right, pointer to the nodes right child

Return: None

Purpose: Sets the right child of the current node
*/
void PyramidNode::SetRight(PyramidNode * right)
{
	this->right = right;
}

/*
Name: SetCard

Parameters: Card card, the card contained in the node

Return: None

Purpose: Sets the card contained in the current node
*/
void PyramidNode::SetCard(Card card)
{
	this->card = card;
}

/*
Name: HasNoChildren

Parameters: None

Return: bool, true if the current node has no children

Purpose: Determine if a node in the pyramid has any valid children
*/
bool PyramidNode::HasNoChildren()
{
	bool temp = false;

	if ((this->left == nullptr && this->right == nullptr) || (this->left->GetCard()->IsNull() && this->right->GetCard()->IsNull()))
	{
		temp = true;
	}

	return temp;
}
