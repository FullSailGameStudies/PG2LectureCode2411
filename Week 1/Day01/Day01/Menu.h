#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//DECLARATIONS
	//add a menu item
	bool AddMenuItem(std::string menuItem);

	// add a method to show the menu
	void DisplayMenu();

private:
	std::vector<std::string> menuItems_;
};

