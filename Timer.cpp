#include "Timer.h"
#include <iostream>
using std::cout;
#include <windows.h>

/*
Name: Timer

Parameters: None

Return: N/A

Purpose: Default constructor for the timer class
*/
Timer::Timer(mutex *mtx) : hours(), minutes(), seconds()
{
	this->mtx = mtx;
}

/*
Name: Timer

Parameters: const Timer &copy, timer to be copied

Return: N/A

Purpose: Copy constructor for the Timer class
*/
Timer::Timer(const Timer & copy) : hours(copy.hours), minutes(copy.minutes), seconds(copy.seconds)
{
	this->mtx = copy.mtx;
}

/*
Name: ~Timer

Parameters: None

Return: N/A

Purpose: Destructor for the Timer class
*/
Timer::~Timer()
{

}

/*
Name: operator=

Parameters: const Timer &rhs, object on the right hand side of the equals sign

Return: A reference to a timer object

Purpose: Defines the behavior of the equals sign with the Timer class
*/
Timer & Timer::operator=(const Timer & rhs)
{
	this->hours = rhs.hours;
	this->minutes = rhs.minutes;
	this->seconds = rhs.seconds;

	return *this;
}

/*
Name: operator<<

Parameters: ostream &os, ostream that will be handling the display
			Timer &time, object to be displayed

Return: A reference to an ostream object

Purpose: Allow a Timer object to be fed into an ostream and be output properly
*/
ostream & operator<<(ostream & os, Timer & time)
{
	os << time.hours << ":" << (time.minutes < 10 ? "0" : "") << time.minutes << ":" << (time.seconds < 10 ? "0" : "") << time.seconds;
	return os;
}

/*
Name: GetHours

Parameters: None

Return: int, the hours of the timer

Purpose: Returns an int representing the hours of the timer
*/
int Timer::GetHours()
{
	return this->hours;
}

/*
Name: GetMinutes

Parameters: None

Return: int, the minutes of the timer

Purpose: Returns an int representing the minutes of the timer
*/
int Timer::GetMinutes()
{
	return this->minutes;
}

/*
Name: GetSeconds

Parameters: None

Return: int, the seconds of the timer

Purpose: Returns an int representing the seconds of the timer
*/
int Timer::GetSeconds()
{
	return this->seconds;
}

/*
Name: Length

Parameters: None

Return: int, the length of the output string

Purpose: Returns the length of the output string
*/
int Timer::Length()
{
	int length = 0;
	stringstream buffer;

	buffer << this->hours << ":" << (this->minutes < 10 ? "0" : "") << this->minutes << ":" << (this->seconds < 10 ? "0" : "") << this->seconds;

	length = buffer.str().length();

	return length;
}

/*
Name: SetHours

Parameters: int hours, number of hours to put on the timer

Return: None

Purpose: Sets the hours parameter of the timer
*/
void Timer::SetHours(int hours)
{
	this->hours = hours;
}

/*
Name: SetMinutes

Parameters: int minutes, number of minutes to put on the timer

Return: None

Purpose: Sets the minutes parameter of the timer
*/
void Timer::SetMinutes(int minutes)
{
	this->minutes = minutes;
}

/*
Name: SetSeconds

Parameters: int seconds, number of seconds to put on the timer

Return: None

Purpose: Sets the seconds parameter of the timer
*/
void Timer::SetSeconds(int seconds)
{
	this->seconds = seconds;
}

/*
Name: Time

Parameters: bool *run, control variable; terminates the timer when false

Return: None

Purpose: Starts the timer, needs to be run in another thread.
*/
void Timer::Time(bool *run)
{
	HANDLE hStdout;
	CONSOLE_SCREEN_BUFFER_INFO temp;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	while (*run)
	{	
		for (int i = 0; i < 60; i++)
		{
			if (this->minutes == 59)
			{
				this->minutes = 0;
			}

			for (int j = 0; j < 60; j++)
			{
				this->mtx->lock();
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				GetConsoleScreenBufferInfo(hStdout, &temp);
				destCoord.X = 0;
				destCoord.Y = 0;
				SetConsoleCursorPosition(hStdout, destCoord);
				cout << this->hours << ":" << (this->minutes < 10 ? "0" : "") << this->minutes << ":" << (this->seconds < 10 ? "0" : "") << this->seconds;
				destCoord = temp.dwCursorPosition;
				SetConsoleCursorPosition(hStdout, destCoord);
				this->mtx->unlock();
				
				if (this->seconds == 59)
				{
					this->seconds = 0;
				}

				if (!*run)
				{
					break;
				}

				this->seconds++;
				Sleep(1000);
			}

			if (!*run)
			{
				break;
			}

			this->minutes++;
		}

		if (!*run)
		{
			break;
		}

		this->hours++;
	}
}