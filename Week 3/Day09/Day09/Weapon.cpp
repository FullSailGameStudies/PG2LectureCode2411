#include <iostream>
#include "Weapon.h"

int numberOfWeapons = 0;//global variable
int Weapon::numberOfWeapons = 0;//initialize the static data

Weapon::Weapon(int range, int damage) : mRange(range), mDamage(damage)
{
}

void Weapon::showMe()
{
	std::cout << "Range: " << mRange << " Damage: " << mDamage << "\n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}
