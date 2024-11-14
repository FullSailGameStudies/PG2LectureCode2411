#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	Weapon::showMe();
	std::cout << "\n\tRounds: " << rounds_ << "\t Magazine: " << magCapacity_;
}
