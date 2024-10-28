#include "Menu.h"
#include <iostream>

//DEFINITIONS
bool Menu::AddMenuItem(std::string menuItem)
{
	bool result = true;
	//add to the vector
	for (size_t i = 0; i < menuItems_.size(); i++)
	{
		// _stricmp
		//	returns a number.
		//  < 0 s1 is LESS than s2
		//  == 0 s1 EQUALS s2
		//  > 0 s1 is GREATER than s2
		//int compResult = _stricmp(menuItems_[i].c_str(), menuItem.c_str());
		//if (compResult == 0)//menuItems_[i] == menuItem)
		if(_stricmp(menuItems_[i].c_str(), menuItem.c_str()) == 0)
			return false;
	}
	menuItems_.push_back(menuItem);
	return result;
}

void Menu::DisplayMenu()
{
	std::cout << "\nPG2 Menu\n---------\n";
	//std::cout << menuItems_;
	for (std::string& menuItem : menuItems_)//otto?
	{
		std::cout << menuItem << "\n";
	}

	//iterator loop
	//	iterators acts like pointers
	//	they are objects that "point" to the items in the vector
	for (std::vector<std::string>::iterator i = menuItems_.begin(); i != menuItems_.end(); i++)
	{
		//* to "dereference"
		//-> to go to the object

		std::cout << *i << "\n";
	}


	//erase the 3rd item in menuItems_
	menuItems_.erase(menuItems_.begin() + 2);
}
