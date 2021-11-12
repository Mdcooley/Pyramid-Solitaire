#include "HighScoreList.h"

/*
Name: HighScoreList

Parameters: None

Return: N/A

Purpose: Default constructor for HighScoreList
*/
HighScoreList::HighScoreList()
{
	this->maxList = false;
	this->inserted = false;
	this->length = FileLength(maxList);
	this->name = new char *[length];
	this->score = new gameTime[length];
}

/*
Name: HighScoreList

Parameters: HighScoreList &copy, list to be copied

Return: N/A

Prupose: Copy constructor for HighScoreList
*/
HighScoreList::HighScoreList(const HighScoreList & copy)
{
	this->maxList = copy.maxList;
	this->inserted = copy.inserted;
	this->length = copy.length;

	this->name = new char *[length];
	this->score = new gameTime[length];
}

/*
Name: ~HighScoreList

Parameters: None

Return: N/A

Purpose: Deconstructor for HighScoreList
*/
HighScoreList::~HighScoreList()
{
	Cleanup(this->name, this->score, this->length);
}

/*
Name: operator=

Parameters: HighScoreList &rhs, list on the right side of the equals sign

Return: A reference to a HighScoreList object

Purpose: Defines the behavior of the equals sign with the HighScoreList class
*/
HighScoreList & HighScoreList::operator=(const HighScoreList & rhs)
{
	this->maxList = rhs.maxList;
	this->length = rhs.length;

	this->name = new char *[length];
	this->score = new gameTime[length];

	return *this;
}

/*
Name: OutputHighScore

Parameters: char **& name, array of names (parallel with score).
			char **& score, array of scores (parallel with name).
			int length, length of the arrays.

Return: None

Purpose: Output a table of high scores
*/
void HighScoreList::OutputHighScore(char **& name, gameTime *& score, int length)
{
	int width1 = MaxLength(name, length) + 5, width2 = MaxLength(score, length) + 5, width3 = ((width1 + width2) / 2) + 6;

	if (!(this->inserted || this->maxList))
	{
		length -= 1;
	}

	system("CLS");

	cout << setw(width3) << "High Scores" << endl;
	cout << "Name" << setw(width1 + width2 - 4) << right << "Times" << endl;

	for (int a = 0; a < width1 + width2; a++)
	{
		cout << "-";
	}

	cout << endl;

	for (int i = 0; i < length; i++)
	{
		cout << setw(width1) << left << name[i] << right << setw(width2 - 6) << score[i].hours
			<< ":" << (score[i].minutes < 10 ? "0" : "") << score[i].minutes << ":" << (score[i].seconds < 10 ? "0" : "") << score[i].seconds << endl;
	}
}

/*
Name: MaxLength

Parameters: char **& cstring, array of cstrings.
			int length, length of the array.

Return: int size, equal to the length of the longest cstring.

Purpose: Determine the size of the longest cstring in an array
*/
int HighScoreList::MaxLength(char **& cstring, int length)
{
	int size = 0;

	for (int i = 0; i < length; i++)
	{
		strlen(cstring[i]) > size ? size = strlen(cstring[i]) : size;
	}

	return size;
}

/*
Name: MaxLength

Parameters: gameTime *& score, array of score times.
			int length, length of the array.

Return: int size, length of the longest time in the array.

Purpose: Determine the length of the longest time in an array.
*/
int HighScoreList::MaxLength(gameTime *& score, int length)
{
	int size = 0;

	for (int i = 0; i < length; i++)
	{
		if (score[i].length > size)
		{
			size = score[i].length;
		}
	}

	return size + 2;
}

/*
Name: FileLength

Parameters: None

Return: int count, number of lines of data in a file.

Purpose: Determine how many lines of data are in a file.
*/
int HighScoreList::FileLength(bool & maxList)
{
	ifstream highScoreList("HighScoreList.txt");
	int count = 0;
	char temp[MAX_BUFFER] = { '\0' };

	if (highScoreList.is_open())
	{
		while (highScoreList.getline(temp, MAX_BUFFER))
		{
			count++;
		}

		highScoreList.close();
	}
	else
	{
		cout << "Error opening file!\nTerminating Program" << endl;
	}

	if (count >= 10)
	{
		maxList = true;
	}
	else
	{
		count++;
	}

	return count;
}

/*
Name: ReadList

Parameters: char **& name, array to contain names of high scorers.
			char **& score, array to contain scores of high scorers.
			int length, length of both arrays & number of lines in file.

Return: None

Purpose: Read a file containing the high score list into memory
*/
void HighScoreList::ReadList(char **& name, gameTime *& score, int length)
{
	ifstream highScoreList("HighScoreList.txt");
	char temp[MAX_BUFFER];
	char fname[MAX_BUFFER];
	char lname[MAX_BUFFER];

	if (highScoreList.is_open())
	{
		for (int i = 0; i < length; i++)
		{
			highScoreList >> fname;
			highScoreList >> lname;
			name[i] = new char[strlen(fname) + strlen(lname) + 2];
			strcpy(name[i], fname);
			strcat(name[i], " ");
			strcat(name[i], lname);

			highScoreList.getline(temp, MAX_BUFFER, ':');
			score[i].length = strlen(temp);
			score[i].hours = atoi(temp);

			highScoreList.getline(temp, MAX_BUFFER, ':');
			score[i].length += strlen(temp);
			score[i].minutes = atoi(temp);

			highScoreList.getline(temp, MAX_BUFFER);
			score[i].length += strlen(temp);
			score[i].seconds = atoi(temp);
		}

		highScoreList.close();
	}
	else
	{
		cout << "Error opening file!\nTerminating Program" << endl;
	}
}

/*
Name: Cleanup

Parameters: char **& name, array of names from the high score list.
			char **& score, array of scores from the high score list.
			int length, length of the arrays.

Return: None

Purpose: Delete the memory that was dynamically allocated to contain the high score list
*/
void HighScoreList::Cleanup(char **& name, gameTime *& score, int length)
{
	for (int i = 0; i < length; i++)
	{
		delete[] * (name + i);
	}

	delete[] name;
	delete score;

	name = nullptr;
}

/*
Name: SortScores

Parameters: char **& name, array of names of high scorers.
			gameTime *& score, array of scores of high scorers.
			int length, length of the arrays.

Return: None

Purpose: Sort the high score list, with the lowest times (scores) being at the top.
*/
void HighScoreList::SortScores(char **& name, gameTime *& score, int length)
{
	char * tempName;
	gameTime tempScore;
	bool swapped;

	for (int i = 0; i < (length); i++)
	{
		swapped = false;

		for (int x = 0; x < (length - i - 1); x++)
		{
			if (LongerTime(score[x], score[x + 1]))
			{
				tempName = name[x];
				tempScore = score[x];

				name[x] = name[x + 1];
				score[x] = score[x + 1];

				name[x + 1] = tempName;
				score[x + 1] = tempScore;

				swapped = true;
			}
		}

		if (swapped == false)
		{
			break;
		}
	}
}

/*
Name: LongerTime

Parameters: gameTime score1, the score to compare against.
			gameTime score2, the score to compare with.

Return: bool isHigher, true if score1 is a longer time than score2.

Purpose: Determin if one score is a longer time than a second score, used for sorting.
*/
bool HighScoreList::LongerTime(gameTime score1, gameTime score2)
{
	bool isHigher = false;

	if (score1.hours > score2.hours)
	{
		isHigher = true;
	}
	else if (score1.hours == score2.hours)
	{
		if (score1.minutes > score2.minutes)
		{
			isHigher = true;
		}
		else if (score1.minutes == score2.minutes)
		{
			if (score1.seconds > score2.seconds)
			{
				isHigher = true;
			}
		}
	}

	return isHigher;
}

/*
Name: SaveList

Parameters: char **& name, array of names of high scorers.
			gameTime *& score, array of scores of high scorers.
			int length, length of the arrays.

Return: None

Purpose: Save the high score list to a text file, so it can be accessed in later games
*/
void HighScoreList::SaveList(char **& name, gameTime *& score, int length)
{
	ofstream highScoreList("HighScoreList.txt");

	if (highScoreList.is_open())
	{
		for (int i = 0; i < length; i++)
		{
			highScoreList << name[i] << " " << score[i].hours << ":" << score[i].minutes << ":" << score[i].seconds << endl;
		}

		highScoreList.close();
	}
	else
	{
		cout << "Error opening file!\nTerminating Program" << endl;
	}
}

/*
Name: InsertScore

Parameters: char **& name, array of names of high scorers.
			gameTime *& score, array of high scores.
			int length, length of the arrays.

Return: None

Purpose: Insert a new score into the highs score list if it is a faster time than any of the current scores or if the high score list is not yet full
*/
//Note that this will accept some inputs (such as a blank input) that will later break the read function.
//That is because this is not my final insert score function, I primarily made it for testing purposes.
void HighScoreList::InsertScore(char **& name, gameTime *& score, gameTime newScore, int length, bool maxList)
{
	system("CLS");
	
	char tempName[MAX_BUFFER] = { '\0' };

	if (!maxList || LongerTime(score[length - 1], newScore))
	{
		cout << "High Score!" << endl;
		cout << "Please enter your name: ";
		
		do
		{
			cin.getline(tempName, MAX_BUFFER);

			if (!regex_match(tempName, NAME))
			{
				system("CLS");
				cout << "Please enter a valid name (Two words, containing only letters, commas, periods, apostrophes, or hyphens): ";
			}
		} while (!regex_match(tempName, NAME));

		delete name[length - 1];
		name[length - 1] = new char[strlen(tempName) + 1];
		strcpy(name[length - 1], tempName);
		score[length - 1] = newScore;
		this->inserted = true;
	}
}

/*
Name: DisplayList

Parameters: None

Return: None

Purpose: Runs all the logic for reading, outputting, sorting, and saving the high score list
*/
void HighScoreList::DisplayList()
{
	ReadList(this->name, this->score, this->length);
	OutputHighScore(this->name, this->score, this->length);
}

/*
Name: NewHighScore

Parameters: gameTime newScore, the time to be (possibly) inserted into the list

Return: None

Purpose: Read in the high score list, insert a score, display the list, and then save it.
*/
void HighScoreList::NewHighScore(gameTime newScore)
{
	ReadList(this->name, this->score, this->length);
	InsertScore(this->name, this->score, newScore, this->length, this->maxList);
	SortScores(this->name, this->score, this->length);
	OutputHighScore(this->name, this->score, this->length);
	SaveList(this->name, this->score, this->length);

	system("PAUSE");
}