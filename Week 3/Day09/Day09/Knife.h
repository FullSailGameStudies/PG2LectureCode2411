#pragma once
#include "Weapon.h"
#include <iostream>
class Knife : public Weapon
{
public:
	Knife(int range, int damage, bool serated, float length)
		: 
		Weapon(range,damage), 
		serrated_(serated), 
		length_(length)
	{
	}

	//
	// non-static methods have a "hidden" parameter
	// called "this"
	// non-static methods can access non-static AND static members
	void showMe() override //Knife* this
	{
		Weapon::showMe();
		std::cout << "I am a" << ((serrated_) ? " serrated " : " ") << " knife that is ";
		std::cout << length_ << " long.\n";
	}

	// static methods do NOT have a "this" parameter
	// static methods can ONLY access other static members
	// static methods can NOT access non-static members b/c there is NO this
	static void DescribeMe()
	{
		std::cout << "I am a knife.\n";
		//std::cout << length_ << " long.\n";
	}

private:
	bool serrated_;
	float length_;
};

