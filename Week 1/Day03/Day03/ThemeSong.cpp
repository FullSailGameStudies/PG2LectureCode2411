#include "ThemeSong.h"
#include <iostream>
#include "../../../Shared/Console/Console.h"

void ThemeSong::batTheme(int numberOfNas)
{
	int w = Console::GetWindowWidth(), h = Console::GetWindowHeight();

	//for (size_t i = 0; i < numberOfNas; i++)
	int count = 0;
	while(true)
	{
		Console::SetCursorPosition(rand() % w, rand() % h);
		Console::Write("na ", (ConsoleColor)(rand() % 8));
		if (numberOfNas != 0)
		{
			count++;
			if (count > numberOfNas) break;
		}
		if(rand() % 1000 == 500) 
			std::cout << "BATMAN!!!!";
	}

	Console::SetCursorPosition(w / 2 - 5, h / 2);
	std::cout << "BATMAN!!!!\n";
}
