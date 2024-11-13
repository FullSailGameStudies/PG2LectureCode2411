#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds_, int magCapacity_) :
		Weapon(range, damage),
		rounds_(rounds_), 
		magCapacity_(magCapacity_)
	{
	}

	int Rounds() const { return rounds_; }
	int MagCapacity() const { return magCapacity_; }

	void Rounds(int rounds)
	{
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}
	void MagCapacity(int magCapacity)
	{
		if (magCapacity > 0 && magCapacity < 16)
			magCapacity_ = magCapacity;
	}

private:
	int rounds_, magCapacity_;

};

