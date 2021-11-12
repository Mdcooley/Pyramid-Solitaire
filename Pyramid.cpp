#include "Pyramid.h"

/*
Name: Pyramid

Parameters: None

Return: N/A

Purpose: Default constructor for the Pyramid class
*/
Pyramid::Pyramid()
{
	this->head = nullptr;
}

/*
Name: Pyramid

Parameters: const Pyramid &copy, Pyramid to be copied

Return: N/A

Purpose: Copy constructor for the Pyramid class
*/
//This does preform a shallow copy, but only because a deep copy is not needed in this program
Pyramid::Pyramid(const Pyramid & copy)
{
	this->head = copy.head;
}

/*
Name: ~Pyramid

Parameters: None

Return: N/A

Purpose: Destructor for the Pyramid class
*/
Pyramid::~Pyramid()
{
	Cleanup(head);
}

/*
Name: operator=

Parameters: const Pyramid &rhs, object of the right side of the equals sign

Return: A reference to a Pyramid object

Purpose: Defines the behavior of the = operator with the Pyramid class
*/
//This does preform a shallow copy, but only because a deep copy is not needed in this program
Pyramid & Pyramid::operator=(const Pyramid & rhs)
{
	this->head = rhs.head;

	return *this;
}

/*
Name: Create

Parameters: Deck &deck, a deck of cards

Return: None

Purpose: Deals out the Pyramid from the deck
*/
void Pyramid::Create(Deck & deck)
{
	PyramidNode * current;
	PyramidNode * next;

	head = new PyramidNode(deck.Peek()->GetCard());
	delete deck.Pop();
	current = head;

	for (int i = 1; i < 7; i++)
	{
		current->SetLeft(new PyramidNode(deck.Peek()->GetCard()));
		delete deck.Pop();
		next = current->GetLeft();

		for (int j = 0; j < i; j++)
		{
			current->SetRight(new PyramidNode(deck.Peek()->GetCard()));
			delete deck.Pop();
			current->GetLeft()->SetNext(current->GetRight());

			if (current->GetNext() != nullptr)
			{
				current->GetNext()->SetLeft(current->GetRight());
				current = current->GetNext();
			}
		}

		current = next;
	}
}

/*
Name: HasCard

Parameters: PyramidNode * node, PyramidNode to check
			Card card, Card to be checked for

Return: bool, true if the Pyramid contains the secified card

Purpose: Recursive function the check if the Pyramid has a card
*/
bool Pyramid::HasCard(PyramidNode * node, Card card)
{
	bool hasCard = false;

	if (node->GetCard()->IsEqual(card) && node->HasNoChildren())
	{
		hasCard = true;
	}
	else
	{
		if (node->GetRight() != nullptr && !hasCard)
		{
			hasCard = HasCard(node->GetRight(), card);
		}

		if (node->GetLeft() != nullptr && !hasCard)
		{
			hasCard = HasCard(node->GetLeft(), card);
		}
	}

	return hasCard;
}

/*
Name: RemoveCard

Parameters: PyramidNode * node, PyramidNode to check
			Card card, Card to be removed

Return: None

Purpose: Recursive function to remove a specific card from the Pyramid
*/
void Pyramid::RemoveCard(PyramidNode * node, Card card)
{
	bool hasCard = false;
	
	if (node->GetCard()->IsEqual(card) && node->HasNoChildren())
	{
		hasCard = true;
		node->GetCard()->SetRank(-1);
		node->GetCard()->SetSuit(-1);
	}
	else
	{
		if (node->GetRight() != nullptr && !hasCard)
		{
			RemoveCard(node->GetRight(), card);
		}

		if (node->GetLeft() != nullptr && !hasCard)
		{
			RemoveCard(node->GetLeft(), card);
		}
	}
}

/*
Name: IsEmpty

Parameters: None

Return: bool, true if no card remain in the Pyramid

Purpose: Determines if the pyramid has all card removed (i.e. victory has been achieved)
*/
bool Pyramid::IsEmpty()
{
	return (this->head->GetCard()->GetRank() < 0 && this->head->GetCard()->GetSuit() < 0);
}

/*
Name: Display

Parameters: None

Return: None

Purpose: Displays the Pyramid to the console
*/
void Pyramid::Display()
{
	PyramidNode * current = this->head;
	PyramidNode * temp = this->head;
	PyramidNode * next;

	for (int i = 0; i < 7; i++)
	{
		next = current->GetLeft();

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << (current->GetCard()->IsNull() ? "          " : "|--------|");

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			if (current->GetCard()->IsNull())
			{
				cout << "          ";
			}
			else
			{
				cout << (current->GetCard()->GetRank() == 10 ? "|     " : "|      ");
				current->GetCard()->PrintData();
				cout << "|";
			}

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << (current->GetCard()->IsNull() ? "          " : "|        |");

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << (current->GetCard()->IsNull() ? "          " : "|        |");

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << (current->GetCard()->IsNull() ? "          " : "|        |");

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			if (current->GetCard()->IsNull())
			{
				cout << "          ";
			}
			else
			{
				cout << "|";
				current->GetCard()->PrintData();
				cout << (current->GetCard()->GetRank() == 10 ? "     |" : "      |");
			}

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = temp;
		cout << endl;

		for (int w = 0; w < ((7 - i) * 5) - 5; w++)
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; j++)
		{
			cout << (current->GetCard()->IsNull() ? "          " : "|--------|");

			if (current->GetNext() != nullptr)
			{
				current = current->GetNext();
			}
		}

		current = next;
		temp = current;
		cout << endl;
	}
}

/*
Name: Cleanup

Parameters: PyramidNode * node, Top node of the pyramid

Return: None

Purpose: Deletes all nodes from the pyramid to prevent memory leaks
*/
void Pyramid::Cleanup(PyramidNode * node)
{
	for (int index = 0; index < 7; index++)
	{
		PyramidNode *temp = this->head;
		this->head = temp->GetLeft();

		while (temp->GetRight() != nullptr)
		{
			PyramidNode *temp2 = temp;
			temp = temp->GetRight();
			delete temp2;
		}

		delete temp;
	}
}

/*
Name: GetHead

Parameters: None

Return: A pointer to a PyramidNode object

Purpose: Returns a pointer to the head of they Pyramid
*/
PyramidNode * Pyramid::GetHead()
{
	return this->head;
}
