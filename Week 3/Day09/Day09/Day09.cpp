// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Knife.h"
#include "Pistol.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	virtual void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
	void print() override
	{
		base::print();
		std::cout << "Hello derived " << mStr << "\n";
	}
};


int main()
{
	std::vector<base> inv;
	inv.push_back(base(10));
	inv.push_back(derived("D1",15));//????? CONVERTS to a base

	std::vector<base*> inv2;
	inv2.push_back(new base(10));
	inv2.push_back(new derived("D1", 15));//copies the POINTER

	base* basePtr = new derived("D2",45);//UPCAST


	base b1(25);
	derived d1("D1", 15);
	b1 = d1;//what happens? copies the base parts to b1

	{
		std::unique_ptr<base> pBase(new base(420));// std::make_unique<base>(420);
		std::unique_ptr<base> pBaseOther = std::move(pBase);
		pBaseOther->print();
		(*pBaseOther).print();
	}//pBase goes out of scope and its memory is deallocated (deleted)

	base* pBase2 = new base(42);
	base* pBase3 = pBase2;//shallow copy
	pBase2->print();
	(*pBase3).print();
	delete pBase2;

	int num = 5;
	int* pNum = &num;
	int& num2 = num;
	std::cout << num << "\n" << pNum << "\t" << *pNum << "\n" << num2;

	{
		int* pNum2 = new int(5);//allocates on the HEAP
		std::cout << "\n" << pNum2 << "\n" << *pNum2 << "\n";

		int* pNum3 = pNum2;//copies the pointer

		delete pNum2;//release the memory back to the runtime
		pNum2 = nullptr;

		std::cout << "\n" << pNum3 << "\n" << *pNum3 << "\n";

		if (pNum2 != nullptr)
			std::cout << "\n" << pNum2 << "\n" << *pNum2 << "\n";
	}
	std::cin.get();
	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/

	std::vector<std::unique_ptr<Weapon>> dorasBackpack;
	dorasBackpack.push_back(std::make_unique<Knife>(5, 10, true, 0.2f));
	dorasBackpack.push_back(std::make_unique<Knife>(5, 10, true, 0.5f));
	dorasBackpack.push_back(std::make_unique<Knife>(5, 10, true, 1.2f));
	std::unique_ptr<Pistol> pewpew(new Pistol(50, 100, 15, 5));
	dorasBackpack.push_back(std::move(pewpew));

	std::cout << "\n\nDora's Backpack\n";
	for (auto& wpn : dorasBackpack)
	{
		wpn->showMe();
	}
	std::cout << "\n\n";

	//dorasBackpack.push_back(std::make_unique<base>(15));

	Weapon* wpnPtr;
	wpnPtr = new Knife(5, 10, true, 0.3F);
	wpnPtr = new Pistol(50, 100, 15, 5);

	Knife stab(5, 10, true, 0.3F);
	stab.showMe();
	stab.DescribeMe();
	Knife::DescribeMe();

	wpnPtr->showMe();//which showMe gets called? RUNTIME polymorphism
}