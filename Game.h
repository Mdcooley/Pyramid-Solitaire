#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "Deck.h"
#include "Pyramid.h"
#include "Timer.h"
#include "HighScoreList.h"

#include <cwchar>
#include <Windows.h>

#include <fstream>
using std::ifstream;

#include <ctime>
using std::time;

#include <cstdlib>
using std::srand;

#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <regex>
using std::regex;
using std::regex_match;

#include <thread>
using std::thread;

#include <mutex>
using std::mutex;

const regex CARD("(10|[2-9AaQqJjKk])[HhCcDdSs]( (10|[2-9AaQqJjKk])[HhCcDdSs])?");
const regex DRAW("draw", std::regex_constants::icase);
const regex QUIT("quit", std::regex_constants::icase);

static mutex * mtx;

class Game
{
	public:

		/*
		Name: Game

		Parameters: None

		Return: N/A

		Purpose: Constructor for the Game class, creates the deck and stacks, then shuffles and fills the deck
		*/
		Game();

		/*
		Name: Game

		Parameters: Game &copy, game to be copied

		Return: N/A

		Purpose: Copy constructor for game
		*/
		Game(const Game &copy);

		/*
		Name: operator=

		Parameters: Game &rhs, game on the right side of the equals sign

		Return: A reference to a game object

		Purpose: Defines the behavior of the equals sign with the Game class
		*/
		Game & operator=(const Game &rhs);

		/*
		Name: ~Game

		Parameters: None

		Return: N/A

		Purpose: Deconstructor for the Game class
		*/
		~Game();

		/*
		Name: GenerateDeck

		Parameters: int temp[], shuffled array of ints to be used to create the deck

		Return: None

		Purpose: Fills the deck with cards that have their values taken from the array
		*/
		void GenerateDeck(int temp[]);

		/*
		Name: Shuffle

		Parameters: int temp[], array of ints going from 0-51

		Return: None

		Purpose: Takes an array of ints from 0-51 and shuffles them into a random order
		*/
		void Shuffle(int temp[]);

		/*
		Name: Play

		Parameters: None 

		Return: None

		Purpose: Contains the control logic for the game, currently not implemented
		*/
		void Play();

		/*
		Name: DrawThree

		Parameters: None

		Return: None

		Purpose: Draws up to three cards out of the deck and places one into each of the stacks. 
				 If the deck is empty, reconstruct it in the original order from the stacks; emptying them in the process
		*/
		void DrawThree();

		/*
		Name: DisplayRow

		Parameters: None

		Return: None

		Purpose: Outputs a row of cards representing the deck and each of the three stacks, not currently implemented
		*/
		void DisplayRow();

		/*
		Name: OutputDeck

		Parameters: None

		Return: None

		Purpose: Outputs all cards contained in the deck and each of the three stacks, for testing purposes
		*/
		void OutputDeck();

		/*
		Name: ParseInput

		Parameters: string input, the input to be parsed

		Return: int, based on what the input matches

		Purpose: Returns an int based on user input to control a switch
		*/
		int ParseInput(string input);

		/*
		Name: MatchCards

		Parameters: Card card, card to be matched

		Return: None

		Purpose: Determines if a card is a valid match, and removes it if it is
		*/
		bool MatchCards(Card card);

		/*
		Name: MatchCards

		Parameters: Card card1, first card to be matched
					Card card2, second card to be matched

		Return: None

		Purpose: Determines if two cards are a valid match, and removes them from the game if they are
		*/
		bool MatchCards(Card card1, Card card2);

		/*
		Name: CardIsValid

		Parameters: Card card, card to be checked

		Return: bool, true if card is valid to be removed

		Purpose: Checks if a card is in a valid location to be removed
				 i.e. in the pyramid with no children or on top of one of the draw piles
		*/
		bool CardIsValid(Card card, int &location);

		/*
		Name: PrintCthulhu

		Parameters: None

		Return: None

		Purpose: Read in an ASCII art of Cthulhu from a file and print it to the console
		*/
		void PrintCthulhu();

		/*
		Name: PrintIlluminati

		Parameters: None

		Return: None

		Purpose: Read in an ASCII art of the Illuminati symbol from a file and print it to the console
		*/
		void PrintIlluminati();

		/*
		Name: DisplayBoard

		Parameters: None

		Return: None

		Purpose: Lock the current thread and then print the pyramid and the draw row to the console
		*/
		void DisplayBoard();

	private:
		Deck deck; //The deck that will be used to play the game
		Deck stacks[3]; //The three stacks that cards are drawn into during play
		Pyramid pyramid; //The pyramid that will be used to play the game
};