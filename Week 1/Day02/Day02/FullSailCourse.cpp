#include "FullSailCourse.h"
#include <iostream>
#include "Console.h"

void FullSailCourse::FillGrades(std::vector<float>& course)//allows us to modify the variable somewhere else
{
	for (size_t i = 0; i < 10; i++)
	{
		course.push_back(rand() % 10001 / 100.0F);
	}
}

void FullSailCourse::ShowGrades(std::vector<float>& grades)//prevents a copy of the vector
{
	Console::WriteLine("\nPG2 Grades: 2411", ConsoleColor::Yellow);
	Console::WriteLine("___________________", ConsoleColor::Yellow);
	for (size_t i = 0; i < grades.size(); i++)
	{
		Console::SetCursorLeft(4);
		Console::WriteLine(std::to_string(grades[i]), ConsoleColor::Cyan);
		//std::cout << grades[i] << "\n";
	}
}
