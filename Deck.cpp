#include "Deck.h"

/*
Name: Deck

Parameters: None

Return: N/A

Purpose: Constructor for the Deck class
*/
Deck::Deck()
{
	Deck::top = nullptr;
	Deck::bottom = nullptr;
}

/*
Name: Deck

Parameters: Deck &copy, deck to be copied

Return: N/A

Purpose: Copy constructor for deck
*/
Deck::Deck(const Deck &copy)
{
	this->top = copy.top;
	this->bottom = copy.bottom;
}

/*
Name: operator=

Parameters: Deck &rhs, deck on the right hand side of the equals sign

Return: A reference to a deck

Purpose: Defines the behavior of the = operator for the Deck class
*/
Deck & Deck::operator=(const Deck &rhs)
{
	this->top = rhs.top;
	this->bottom = rhs.bottom;

	return *this;
}

/*
Name: Deck

Parameters: DeckNode * node, desired top node of the list

Return: N/A

Purpose: Overloaded constructor for the Deck class, sets the first node immediatley
*/
Deck::Deck(DeckNode * node)
{
	Deck::top = node;
	Deck::bottom = node;
}

/*
Name: ~Deck

Parameters: None

Return: N/A

Purpose: Deconstructor for the Deck class, deletes all nodes in the stack to prevent memory leaks
*/
Deck::~Deck()
{
	if (!IsEmpty())
	{
		DeckNode * temp;

		while (!IsEmpty())
		{
			if (top == bottom)
			{
				temp = top;
				top = nullptr;
				bottom = nullptr;
				temp->SetPrevious(nullptr);
				temp->SetNext(nullptr);
				delete temp;
			}
			else
			{
				temp = top;
				top = top->GetNext();

				temp->SetPrevious(nullptr);
				temp->SetNext(nullptr);
				delete temp;
			}
		}
	}
}

/*
Name: Push

Parameters: DeckNode * card, node to be placed on the stack

Return: None

Purpose: Pushes a new node onto the top of the stack
*/
void Deck::Push(DeckNode * node)
{
	if (node != nullptr)
	{
		if (IsEmpty())
		{
			top = node;
			bottom = node;
		}
		else
		{
			top->SetPrevious(node);
			node->SetNext(top);
			top = node;
		}
	}
}

/*
Name: PlaceOnBottom

Parameters: DeckNode * card, node to be placed on the stack

Return: None

Purpose: Places a new node onto the bottom of the stack (which means it's not technically a stack then)
*/
void Deck::PlaceOnBottom(DeckNode * node)
{
	if (node != nullptr)
	{
		if (IsEmpty())
		{
			top = node;
			bottom = node;
		}
		else
		{
			bottom->SetNext(node);
			node->SetPrevious(bottom);
			bottom = node;
		}
	}
}

/*
Name: IsEmpty

Parameters: None

Return: bool, true if the stack is empty and false otherwise

Purpose: Determine if the stack containes any nodes and returns an appropriate value
*/
bool Deck::IsEmpty()
{
	bool isEmpty = false;
	
	if (Deck::top == nullptr && Deck::bottom == nullptr)
	{
		isEmpty = true;
	}

	return isEmpty;
}

/*
Name: Pop

Parameters: None

Return: DeckNode *, the (former) top node of the stack

Purpose: Removes the top node of the stack, and then returns it
*/
DeckNode * Deck::Pop()
{
	DeckNode * temp;

	if (IsEmpty())
	{
		temp = nullptr;
	}
	else
	{
		temp = top;

		if (top == bottom)
		{
			top = nullptr;
			bottom = nullptr;
		}
		else
		{
			top = top->GetNext();
			top->SetPrevious(nullptr);

			temp->SetPrevious(nullptr);
			temp->SetNext(nullptr);
		}
	}

	return temp;
}

/*
Name: Peek

Parameters: None

Return: DeckNode *, the (current) top node of the stack

Purpose: Returns the top node of the stack without removing it
*/
DeckNode * Deck::Peek()
{
	return Deck::top;
}

/*
Name: GetBottom

Parameters: None

Return: DeckNode *, the (current) bottom node of the stack

Purpose: Returns the bottom node of the stack without removing it
*/
DeckNode * Deck::GetBottom()
{
	return Deck::bottom;
}