#define _CRTDBG_MAP_ALLOC

#include "Game.h"
#include "HighScoreList.h"

const regex MENU("[1-3]");

void PrintTitle();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("mode 650");
	char input[256] = { '\0' };
	int control = 0;

	do
	{
		CONSOLE_FONT_INFOEX con;
		con.cbSize = sizeof(con);
		con.nFont = 0;
		con.dwFontSize.X = 0;                   // Width of each character in the font
		con.dwFontSize.Y = 16;                  // Height
		con.FontFamily = FF_DONTCARE;
		con.FontWeight = FW_NORMAL;
		std::wcscpy(con.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &con);
		system("mode 650");

		PrintTitle();
		cout << "1. Play Game" << endl;
		cout << "2. High Scores" << endl;
		cout << "3. Quit" << endl;
		cout << "Select menu option: ";

		do
		{
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(input, 256);
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			if (!regex_match(input, MENU));
			{
				system("CLS");
				PrintTitle();
				cout << "1. Play Game" << endl;
				cout << "2. High Scores" << endl;
				cout << "3. Quit" << endl;
				cout << "Invalid menu option, please try again: ";
			}
		} while (!regex_match(input, MENU));

		control = atoi(input);

		switch (control)
		{
			case 1:
			{
				Game game;
				game.Play();
				break;
			}
			case 2:
			{
				HighScoreList list;
				list.DisplayList();
				system("PAUSE");
				break;
			}
			case 3:
			{
				control = 3;
				break;
			}
		}
	} while (control != 3);

	return 0;
}

void PrintTitle()
{
	cout << "                               .----------------." << endl;
	cout << "                              | .--------------. |" << endl;
	cout << "                              | |    _______   | |" << endl;
	cout << "                              | |   /  ___  |  | |" << endl;
	cout << "                              | |  |  (__ \\_|  | |" << endl;
	cout << "                              | |   '.___`-.   | |" << endl;
	cout << "                              | |  |`\\____) |  | |" << endl;
	cout << "                              | |  |_______.'  | |" << endl;
	cout << "                              | |              | |" << endl;
	cout << "                              | '--------------' |" << endl;
	cout << "                               '----------------' " << endl;
	cout << "                     .----------------.  .----------------. " << endl;
	cout << "                    | .--------------. || .--------------. |" << endl;
	cout << "                    | |     ____     | || |   _____      | |" << endl;
	cout << "                    | |   .'    `.   | || |  |_   _|     | |" << endl;
	cout << "                    | |  /  .--.  \\  | || |    | |       | |" << endl;
	cout << "                    | |  | |    | |  | || |    | |   _   | |" << endl;
	cout << "                    | |  \\  `--'  /  | || |   _| |__/ |  | |" << endl;
	cout << "                    | |   `.____.'   | || |  |________|  | |" << endl;
	cout << "                    | |              | || |              | |" << endl;
	cout << "                    | '--------------' || '--------------' |" << endl;
	cout << "                     '----------------'  '----------------' " << endl;
	cout << "           .----------------.  .----------------.  .----------------. " << endl;
	cout << "          | .--------------. || .--------------. || .--------------. |" << endl;
	cout << "          | |     _____    | || |  _________   | || |      __      | |" << endl;
	cout << "          | |    |_   _|   | || | |  _   _  |  | || |     /  \\     | |" << endl;
	cout << "          | |      | |     | || | |_/ | | \\_|  | || |    / /\\ \\    | |" << endl;
	cout << "          | |      | |     | || |     | |      | || |   / ____ \\   | |" << endl;
	cout << "          | |     _| |_    | || |    _| |_     | || | _/ /    \\ \\_ | |" << endl;
	cout << "          | |    |_____|   | || |   |_____|    | || ||____|  |____|| |" << endl;
	cout << "          | |              | || |              | || |              | |" << endl;
	cout << "          | '--------------' || '--------------' || '--------------' |" << endl;
	cout << "           '----------------'  '----------------'  '----------------' " << endl;
	cout << " .----------------.  .----------------.  .----------------. " << endl;
	cout << "| .--------------. || .--------------. || .--------------. |" << endl;
	cout << "| |     _____    | || |  _______     | || |  _________   | |" << endl;
	cout << "| |    |_   _|   | || | |_   __ \\    | || | |_   ___  |  | |" << endl;
	cout << "| |      | |     | || |   | |__) |   | || |   | |_  \\_|  | |" << endl;
	cout << "| |      | |     | || |   |  __ /    | || |   |  _|  _   | |" << endl;
	cout << "| |     _| |_    | || |  _| |  \\ \\_  | || |  _| |___/ |  | |" << endl;
	cout << "| |    |_____|   | || | |____| |___| | || | |_________|  | |" << endl;
	cout << "| |              | || |              | || |              | |" << endl;
	cout << "| '--------------' || '--------------' || '--------------' |" << endl;
	cout << " '----------------'  '----------------'  '----------------'" << endl;
}
