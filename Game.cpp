#include "Game.h"

/*
Name: Game

Parameters: None

Return: N/A

Purpose: Constructor for the Game class, creates the deck and stacks, then shuffles and fills the deck
*/
Game::Game()
{
	mtx = new mutex;
	
	int temp[52];
	srand(time(0));

	for (int b = 0; b < 52; b++)
	{
		temp[b] = b;
	}

	Shuffle(temp);

	GenerateDeck(temp);

	pyramid.Create(this->deck);
}

/*
Name: Game

Parameters: Game &copy, game to be copied

Return: N/A

Purpose: Copy constructor for game
*/
Game::Game(const Game & copy)
{
	this->deck = copy.deck;

	for (int i = 0; i < 3; i++)
	{
		this->stacks[i] = copy.stacks[i];
	}
}

/*
Name: operator=

Parameters: Game &rhs, game on the right side of the equals sign

Return: A reference to a game object

Purpose: Defines the behavior of the equals sign with the Game class
*/
Game & Game::operator=(const Game & rhs)
{
	this->deck = rhs.deck;

	for (int i = 0; i < 3; i++)
	{
		this->stacks[i] = rhs.stacks[i];
	}

	return *this;
}

/*
Name: ~Game

Parameters: None

Return: N/A

Purpose: Deconstructor for the Game class
*/
Game::~Game()
{
	delete mtx;
}

/*
Name: GenerateDeck

Parameters: int temp[], shuffled array of ints to be used to create the deck

Return: None

Purpose: Fills the deck with cards that have their values taken from the array
*/
void Game::GenerateDeck(int temp[])
{
	DeckNode * node;

	for (int i = 0; i < 52; i++)
	{
		Card card(temp[i]);
		node = new DeckNode(card);
		deck.PlaceOnBottom(node);
	}
}

/*
Name: Shuffle

Parameters: int temp[], array of ints going from 0-51

Return: None

Purpose: Takes an array of ints from 0-51 and shuffles them into a random order
*/
void Game::Shuffle(int temp[])
{
	int store = 0, shuffle = 0;

	for (int a = 0; a < 3; a++)
	{
		for (int x = 0; x < 52; x++)
		{
			for (int i = 0; i < 52; i++)
			{
				shuffle = rand() % 52;

				store = temp[shuffle];
				temp[shuffle] = temp[i];
				temp[i] = store;
			}
		}
	}
}

/*
Name: Play

Parameters: None

Return: None

Purpose: Contains the control logic for the game, currently not implemented
*/
void Game::Play()
{	
	int control = 0, temp = 0;;
	string input, card1, card2;
	bool victory = false, removed = false, run = true;
	
	Timer gameScore(mtx);
	thread t1(&Timer::Time, &gameScore, &run);

	DisplayBoard();

	cout << "Input string: ";

	do
	{
		getline(cin, input);

		control = ParseInput(input);

		switch (control)
		{
			case 1:
			{
				if (input.length() > 3)
				{
					card1 = input.substr(0, input.find(' '));
					card2 = input.substr(input.find(' ') + 1, input.length());

					Card match1(card1);
					Card match2(card2);

					removed = MatchCards(match1, match2);

					DisplayBoard();

					if (removed)
					{
						cout << "Enter move: ";
					}
					else
					{
						cout << "Invalid match: ";
					}
				}
				else
				{
					Card match(input);

					removed = MatchCards(match);

					DisplayBoard();

					if (removed)
					{
						cout << "Enter move: ";
					}
					else
					{
						cout << "Invalid choice: ";
					}
				}
				break;
			}
			case 2:
			{
				DrawThree();
				DisplayBoard();
				cout << "Enter move: ";
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				DisplayBoard();
				cout << "Invalid command (option are draw, quit, or 1-2 cards entered by rank and suit): ";
			}
		}

		if (pyramid.IsEmpty())
		{
			victory = true;
		}
	} while (!victory && control != 3);

	run = false;
	t1.join();

	if (!victory)
	{
		PrintCthulhu();
	}
	else
	{
		HighScoreList list;
		gameTime newScore{ gameScore.GetHours(), gameScore.GetMinutes(), gameScore.GetSeconds(), gameScore.Length() };

		list.NewHighScore(newScore);
		
		PrintIlluminati();
	}
}

/*
Name: DrawThree

Parameters: None

Return: None

Purpose: Draws up to three cards out of the deck and places one into each of the stacks.
		 If the deck is empty, reconstruct it in the original order from the stacks; emptying them in the process
*/
void Game::DrawThree()
{
	if (deck.IsEmpty())
	{
		while (!(stacks[0].IsEmpty() && stacks[1].IsEmpty() && stacks[2].IsEmpty()))
		{
			deck.Push(stacks[2].Pop());
			deck.Push(stacks[1].Pop());
			deck.Push(stacks[0].Pop());
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			stacks[i].Push(deck.Pop());
		}
	}
}

/*
Name: DisplayRow

Parameters: None

Return: None

Purpose: Outputs a row of cards representing the deck and each of the three stacks
*/
void Game::DisplayRow()
{
	cout << "\n\n\n";
	
	cout << (deck.IsEmpty() ? "          " : "|--------|") << "     " << (stacks[0].IsEmpty() ? "          " : "|--------|") 
		 << "     " << (stacks[1].IsEmpty() ? "          " : "|--------|") << "     " << (stacks[2].IsEmpty() ? "          " : "|--------|") << endl;
	cout << (deck.IsEmpty() ? "          " : "|~~~~~~~~|") << "     ";

	if (stacks[0].IsEmpty())
	{
		cout << "          " << "     ";
	}
	else
	{
		cout << (stacks[0].Peek()->GetCard().GetRank() == 10 ? "|     " : "|      ");
		stacks[0].Peek()->GetCard().PrintData();
		cout << "|" << "     ";
	}

	if (stacks[1].IsEmpty())
	{
		cout << "          " << "     ";
	}
	else
	{
		cout << (stacks[1].Peek()->GetCard().GetRank() == 10 ? "|     " : "|      ");
		stacks[1].Peek()->GetCard().PrintData();
		cout << "|" << "     ";
	}

	if (stacks[2].IsEmpty())
	{
		cout << "          " << endl;
	}
	else
	{
		cout << (stacks[2].Peek()->GetCard().GetRank() == 10 ? "|     " : "|      ");
		stacks[2].Peek()->GetCard().PrintData();
		cout << "|" << endl;
	}

	cout << (deck.IsEmpty() ? "          " : "|~~~~~~~~|") << "     " << (stacks[0].IsEmpty() ? "          " : "|        |") << "     " 
		 << (stacks[1].IsEmpty() ? "          " : "|        |") << "     " << (stacks[2].IsEmpty() ? "          " : "|        |") << endl;
	cout << (deck.IsEmpty() ? "          " : "|~~~~~~~~|") << "     " << (stacks[0].IsEmpty() ? "          " : "|        |") << "     " 
		 << (stacks[1].IsEmpty() ? "          " : "|        |") << "     " << (stacks[2].IsEmpty() ? "          " : "|        |") << endl;
	cout << (deck.IsEmpty() ? "          " : "|~~~~~~~~|") << "     " << (stacks[0].IsEmpty() ? "          " : "|        |") << "     " 
		 << (stacks[1].IsEmpty() ? "          " : "|        |") << "     " << (stacks[2].IsEmpty() ? "          " : "|        |") << endl;
	cout << (deck.IsEmpty() ? "          " : "|~~~~~~~~|") << "     ";

	if (stacks[0].IsEmpty())
	{
		cout << "          " << "     ";
	}
	else
	{
		cout << "|";
		stacks[0].Peek()->GetCard().PrintData();
		cout << (stacks[0].Peek()->GetCard().GetRank() == 10 ? "     |" : "      |") << "     ";
	}

	if (stacks[1].IsEmpty())
	{
		cout << "          " << "     ";
	}
	else
	{
		cout << "|";
		stacks[1].Peek()->GetCard().PrintData();
		cout << (stacks[1].Peek()->GetCard().GetRank() == 10 ? "     |" : "      |") << "     ";
	}

	if (stacks[2].IsEmpty())
	{
		cout << "          " << endl;
	}
	else
	{
		cout << "|";
		stacks[2].Peek()->GetCard().PrintData();
		cout << (stacks[2].Peek()->GetCard().GetRank() == 10 ? "     |" : "      |") << endl;
	}

	cout << (deck.IsEmpty() ? "          " : "|--------|") << "     " << (stacks[0].IsEmpty() ? "          " : "|--------|") << "     " 
		 << (stacks[1].IsEmpty() ? "          " : "|--------|") << "     " << (stacks[2].IsEmpty() ? "          " : "|--------|") << endl;
}

/*
Name: OutputDeck

Parameters: None

Return: None

Purpose: Outputs all cards contained in the deck and each of the three stacks, for testing purposes
*/
void Game::OutputDeck()
{
	DeckNode * temp;

	cout << "Deck" << endl;

	temp = deck.Peek();

	while (temp != nullptr)
	{
		temp->GetCard().PrintData();
		cout << endl;
		temp = temp->GetNext();
	} 

	for (int i = 0; i < 3; i++)
	{
		cout << "Stack" << endl;

		temp = stacks[i].Peek();


		while (temp != nullptr)
		{
			temp->GetCard().PrintData();
			cout << endl;
			temp = temp->GetNext();
		} 
	}
}

/*
Name: ParseInput

Parameters: string input, the input to be parsed

Return: int, based on what the input matches

Purpose: Returns an int based on user input to control a switch
*/
int Game::ParseInput(string input)
{
	int temp = 0;

	if (regex_match(input, CARD))
	{
		temp = 1;
	}
	else if (regex_match(input, DRAW))
	{
		temp = 2;
	}
	else if (regex_match(input, QUIT))
	{
		temp = 3;
	}

	return temp;
}

/*
Name: MatchCards

Parameters: Card card, card to be matched

Return: None

Purpose: Determines if a card is a valid match, and removes it if it is
*/
bool Game::MatchCards(Card card)
{
	int location = -1;
	bool removed = false;
	
	if (CardIsValid(card, location))
	{
		if (card.GetRank() == 13)
		{
			switch (location)
			{
				case 0:
				case 1:
				case 2:
				{
					delete stacks[location].Pop();
					break;
				}
				case 3:
				{
					pyramid.RemoveCard(pyramid.GetHead(), card);
					break;
				}
			}

			removed = true;
		}
	}

	return removed;
}

/*
Name: MatchCards

Parameters: Card card1, first card to be matched
			Card card2, second card to be matched

Return: None

Purpose: Determines if two cards are a valid match, and removes them from the game if they are
*/
bool Game::MatchCards(Card card1, Card card2)
{
	int location1 = -1, location2 = -1;
	bool removed = false;

	if (CardIsValid(card1, location1) && CardIsValid(card2, location2))
	{
		if (card1.GetRank() + card2.GetRank() == 13)
		{
			switch (location1)
			{
				case 0:
				case 1:
				case 2:
				{
					delete stacks[location1].Pop();
					break;
				}
				case 3:
				{
					pyramid.RemoveCard(pyramid.GetHead(), card1);
					break;
				}
			}

			switch (location2)
			{
				case 0:
				case 1:
				case 2:
				{
					delete stacks[location2].Pop();
					break;
				}
				case 3:
				{
					pyramid.RemoveCard(pyramid.GetHead(), card2);
					break;
				}
			}

			removed = true;
		}
	}

	return removed;
}

/*
Name: CardIsValid

Parameters: Card card, card to be checked

Return: bool, true if card is valid to be removed

Purpose: Checks if a card is in a valid location to be removed
		 i.e. in the pyramid with no children or on top of one of the draw piles
*/
bool Game::CardIsValid(Card card, int &location)
{
	bool isValid = false;

	for (int i = 0; i < 3; i++)
	{
		if (stacks[i].Peek() != nullptr && stacks[i].Peek()->GetCard().IsEqual(card))
		{
			isValid = true;
			location = i;
		}
	}

	if (pyramid.HasCard(pyramid.GetHead(), card))
	{
		isValid = true;
		location = 3;
	}

	return isValid;
}

/*
Name: PrintCthulhu

Parameters: None

Return: None

Purpose: Read in an ASCII art of Cthulhu from a file and print it to the console
*/
void Game::PrintCthulhu()
{
	ifstream file("Cthulhu.txt");
	string temp;

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 6;                   // Width of each character in the font
	cfi.dwFontSize.Y = 6;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode 650");

	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}

		file.close();
	}

	system("PAUSE");
}

/*
Name: PrintIlluminati

Parameters: None

Return: None

Purpose: Read in an ASCII art of the Illuminati symbol from a file and print it to the console
*/
void Game::PrintIlluminati()
{
	ifstream file("Illuminati.txt");
	string temp;

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 6;                   // Width of each character in the font
	cfi.dwFontSize.Y = 6;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system("mode 650");

	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}

		file.close();
	}

	system("PAUSE");
}

/*
Name: DisplayBoard

Parameters: None

Return: None

Purpose: Lock the current thread and then print the pyramid and the draw row to the console
*/
void Game::DisplayBoard()
{
	mtx->lock();
	system("CLS");
	pyramid.Display();
	DisplayRow();
	mtx->unlock();
}
