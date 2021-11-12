#pragma once
#include <iostream>
using std::ostream;

#include<sstream>
using std::stringstream;

#include <Windows.h>

#include <mutex>
using std::mutex;

class Timer
{
	public:
		/*
		Name: Timer

		Parameters: None

		Return: N/A

		Purpose: Default constructor for the timer class
		*/
		Timer(mutex *mtx);

		/*
		Name: Timer

		Parameters: const Timer &copy, timer to be copied

		Return: N/A

		Purpose: Copy constructor for the Timer class
		*/
		Timer(const Timer &copy);

		/*
		Name: ~Timer

		Parameters: None

		Return: N/A

		Purpose: Destructor for the Timer class
		*/
		~Timer();

		/*
		Name: operator=

		Parameters: const Timer &rhs, object on the right hand side of the equals sign

		Return: A reference to a timer object

		Purpose: Defines the behavior of the equals sign with the Timer class
		*/
		Timer & operator=(const Timer &rhs);

		/*
		Name: operator<<

		Parameters: ostream &os, ostream that will be handling the display
					Timer &time, object to be displayed

		Return: A reference to an ostream object

		Purpose: Allow a Timer object to be fed into an ostream and be output properly
		*/
		friend ostream & operator<<(ostream &os, Timer &time);

		/*
		Name: GetHours

		Parameters: None

		Return: int, the hours of the timer

		Purpose: Returns an int representing the hours of the timer
		*/
		int GetHours();

		/*
		Name: GetMinutes

		Parameters: None

		Return: int, the minutes of the timer

		Purpose: Returns an int representing the minutes of the timer
		*/
		int GetMinutes();

		/*
		Name: GetSeconds

		Parameters: None

		Return: int, the seconds of the timer

		Purpose: Returns an int representing the seconds of the timer
		*/
		int GetSeconds();

		/*
		Name: Length

		Parameters: None

		Return: int, the length of the output string

		Purpose: Returns the length of the output string
		*/
		int Length();

		/*
		Name: SetHours

		Parameters: int hours, number of hours to put on the timer

		Return: None

		Purpose: Sets the hours parameter of the timer
		*/
		void SetHours(int hours);

		/*
		Name: SetMinutes

		Parameters: int minutes, number of minutes to put on the timer

		Return: None

		Purpose: Sets the minutes parameter of the timer
		*/
		void SetMinutes(int minutes);

		/*
		Name: SetSeconds

		Parameters: int seconds, number of seconds to put on the timer

		Return: None

		Purpose: Sets the seconds parameter of the timer
		*/
		void SetSeconds(int seconds);

		/*
		Name: Time

		Parameters: bool *run, control variable; terminates the timer when false

		Return: None

		Purpose: Starts the timer, needs to be run in another thread.
		*/
		void Time(bool *run);

	private:
		int hours;
		int minutes;
		int seconds;
		mutex * mtx;
};