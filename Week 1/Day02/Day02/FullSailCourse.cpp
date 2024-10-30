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

void FullSailCourse::ShowGrades(const std::vector<float>& grades)//prevents a copy of the vector
{
	//grades.clear();
	Console::WriteLine("\nPG2 Grades: 2411", ConsoleColor::Yellow);
	Console::WriteLine("___________________", ConsoleColor::Yellow);
	for (size_t i = 0; i < grades.size(); i++)
	{
		Console::SetCursorLeft(4);
		Console::WriteLine(std::to_string(grades[i]), ConsoleColor::Cyan);
		//std::cout << grades[i] << "\n";
	}
}

void FullSailCourse::Stats(const std::vector<float>& grades, float& min, float& max) const
{
	if (grades.size() > 0)
	{
		min = max = grades[0];
		for (int i = 1; i < grades.size(); i++)
		{
			if (grades[i] < min) min = grades[i];
			if (grades[i] > max) max = grades[i];
			//min = std::min(min, grades[i]);
			//max = std::max(max, grades[i]);			
		}
	}
	else
	{
		min = max = 0;
	}
}

const std::string& FullSailCourse::GetName() const
{
	return name_;
}
