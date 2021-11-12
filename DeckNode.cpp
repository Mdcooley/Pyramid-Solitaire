#include "DeckNode.h";

/*
Name: DeckNode

Parameters: None

Return: N/A

Purpose: Constructor for the DeckNode class
*/
DeckNode::DeckNode()
{
	DeckNode::prev = nullptr;
	DeckNode::next = nullptr;
	DeckNode::card;
}

/*
Name: DeckNode

Parameters: DeckNode &copy, DeckNode to be copied

Return: N/A

Purpose: Copy constructor for DeckNode
*/
DeckNode::DeckNode(const DeckNode &copy)
{
	prev = copy.prev;
	next = copy.next;
	card = copy.card;
}

/*
Name: DeckNode

Parameters: Card card, card that the node will be representing

Return: N/A

Purpose: Overloaded constructor for the DeckNode class, assigns the card immediatley
*/
DeckNode::DeckNode(Card card)
{
	DeckNode::card = card;
}

/*
Name: ~DeckNode

Parameters: None

Return: N/A

Purpose: Deconstructor for the DeckNode class
*/
DeckNode::~DeckNode()
{
	/*delete prev;
	delete next;
	delete card;*/
}

/*
Name: GetPrevious

Parameters: None

Return: DeckNode *, pointer to the previous node in the list

Purpose: Return a pointer to the previous node in the list
*/
DeckNode * DeckNode::GetPrevious()
{
	return DeckNode::prev;
}

/*
Name: GetNext

Parameters: None

Return: DeckNode *, pointer to the next node in the list

Purpose: Return a pointer to the next node in the list
*/
DeckNode * DeckNode::GetNext()
{
	return DeckNode::next;
}

/*
Name: GetCard

Parameters: None

Return: Card, the card that the node is storing

Purpose: Returns the card that the node is storing
*/
Card DeckNode::GetCard()
{
	return this->card;
}

/*
Name: SetPrevious

Parameters: DeckNode * prev, pointer to another DeckNode object

Return: None

Purpose: Changes what the previous node being pointed to is
*/
void DeckNode::SetPrevious(DeckNode * prev)
{
	DeckNode::prev = prev;
}

/*
Name: SetNext

Parameters: DeckNode * next, pointer to another DeckNode object

Return: None

Purpose: Changes what the next node being pointed to is
*/
void DeckNode::SetNext(DeckNode * next)
{
	DeckNode::next = next;
}

/*
Name: SetCard

Parameters: Card card, card object to be stored in the node

Return: None

Purpose: Sets the value of the card being stored
*/
void DeckNode::SetCard(Card card)
{
	DeckNode::card = card;
}

/*
Name: operator=

Parameters: DeckNode other, node to be copied

Return: A reference to a deck node

Purpose: Defines the behavior of the equals operator with the DeckNode class
*/
DeckNode & DeckNode::operator=(const DeckNode &other)
{
	prev = other.prev;
	next = other.next;
	card = other.card;
	return *this;
}