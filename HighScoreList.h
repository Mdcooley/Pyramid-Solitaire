/*Pseudocode  for Project Final Project

Solution: Final Project

REQUIREMENT SPECIFICATION:
Inputs(s):
Input Type	Data	                                                            Source
String      Previous high scores in the format <first name> <last name> <time>  HighScoreList.txt
			For example: Matthew Cooley 13:37
Output(s):
Output Type	Data	                                                                                            Destination
String      High scores in the format <full name> | <time>, aligned based on the largest string in each column  Windows console

Constants:
Type	Data	                    Value
int     Max size of input string    256

DESIGN:
Pseudocode:
Start

Determine # of lines in input file

Allocate memory

Read file into memory

Output high score table

Deallocate memory

End
*/
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;
using std::right;
using std::left;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <regex>
using std::regex;
using std::regex_match;

const regex NAME("\\b[A-Za-z,.'\\-]+\\b \\b[A-Za-z,.'\\-]+\\b");

const int MAX_BUFFER = 256;

struct gameTime
{
	int hours;
	int minutes;
	int seconds;
	int length;
};

class HighScoreList
{
	public:
		/*
		Name: HighScoreList

		Parameters: None

		Return: N/A

		Purpose: Default constructor for HighScoreList
		*/
		HighScoreList();

		/*
		Name: HighScoreList

		Parameters: HighScoreList &copy, list to be copied

		Return: N/A

		Prupose: Copy constructor for HighScoreList
		*/
		HighScoreList(const HighScoreList &copy);

		/*
		Name: ~HighScoreList

		Parameters: None

		Return: N/A

		Purpose: Deconstructor for HighScoreList
		*/
		~HighScoreList();

		/*
		Name: operator=

		Parameters: HighScoreList &rhs, list on the right side of the equals sign

		Return: A reference to a HighScoreList object

		Purpose: Defines the behavior of the equals sign with the HighScoreList class
		*/
		HighScoreList & operator=(const HighScoreList &rhs);

		/*
		Name: DisplayList

		Parameters: None

		Return: None

		Purpose: Runs all the logic for reading, outputting, sorting, and saving the high score list
		*/
		void DisplayList();

		/*
		Name: NewHighScore

		Parameters: gameTime newScore, the time to be (possibly) inserted into the list

		Return: None

		Purpose: Read in the high score list, insert a score, display the list, and then save it.
		*/
		void NewHighScore(gameTime newScore);

	private:
		bool maxList; //True if the list has 10 entries
		bool inserted;
		int length; //Number of entries in the list
		char ** name; //Array of names for the list
		gameTime * score; //Array of scores for the list

		/*
		Name: OutputHighScore

		Parameters: char **& name, array of names (parallel with score).
					char **& score, array of scores (parallel with name).
					int length, length of the arrays.

		Return: None

		Purpose: Output a table of high scores
		*/
		void OutputHighScore(char **& name, gameTime *& score, int length);

		/*
		Name: MaxLength

		Parameters: char **& cstring, array of cstrings.
					int length, length of the array.

		Return: int size, equal to the length of the longest cstring.

		Purpose: Determine the size of the longest cstring in an array
		*/
		int MaxLength(char **& cstring, int length);

		/*
		Name: MaxLength

		Parameters: gameTime *& score, array of score times.
					int length, length of the array.

		Return: int size, length of the longest time in the array.

		Purpose: Determine the length of the longest time in an array.
		*/
		int MaxLength(gameTime *& score, int length);

		/*
		Name: FileLength

		Parameters: None

		Return: int count, number of lines of data in a file.

		Purpose: Determine how many lines of data are in a file.
		*/
		int FileLength(bool & maxList);

		/*
		Name: ReadList

		Parameters: char **& name, array to contain names of high scorers.
					char **& score, array to contain scores of high scorers.
					int length, length of both arrays & number of lines in file.

		Return: None

		Purpose: Read a file containing the high score list into memory
		*/
		void ReadList(char **& name, gameTime *& score, int length);

		/*
		Name: Cleanup

		Parameters: char **& name, array of names from the high score list.
					char **& score, array of scores from the high score list.
					int length, length of the arrays.

		Return: None

		Purpose: Delete the memory that was dynamically allocated to contain the high score list
		*/
		void Cleanup(char **& name, gameTime *& score, int length);

		/*
		Name: SortScores

		Parameters: char **& name, array of names of high scorers.
					gameTime *& score, array of scores of high scorers.
					int length, length of the arrays.

		Return: None

		Purpose: Sort the high score list, with the lowest times (scores) being at the top.
		*/
		void SortScores(char **& name, gameTime *& score, int length);

		/*
		Name: LongerTime

		Parameters: gameTime score1, the score to compare against.
					gameTime score2, the score to compare with.

		Return: bool isHigher, true if score1 is a longer time than score2.

		Purpose: Determin if one score is a longer time than a second score, used for sorting.
		*/
		bool LongerTime(gameTime score1, gameTime score2);

		/*
		Name: SaveList

		Parameters: char **& name, array of names of high scorers.
					gameTime *& score, array of scores of high scorers.
					int length, length of the arrays.

		Return: None

		Purpose: Save the high score list to a text file, so it can be accessed in later games
		*/
		void SaveList(char **& name, gameTime *& score, int length);

		/*
		Name: InsertScore

		Parameters: char **& name, array of names of high scorers.
					gameTime *& score, array of high scores.
					int length, length of the arrays.

		Return: None

		Purpose: Insert a new score into the highs score list if it is a faster time than any of the current scores or if the high score list is not yet full
		*/
		void InsertScore(char **& name, gameTime *& score, gameTime newScore, int length, bool maxList);
};