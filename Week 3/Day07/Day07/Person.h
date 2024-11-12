#pragma once
#include <string>
class Person
{
public:
	Person(int age, std::string name) : age_(age), name_(name) {}

	int Age() const { return age_; }
	const std::string& Name()const { return name_; }

	void Age(int newAge) {
		if (newAge >= 0 && newAge <= 120)
			age_ = newAge;
	}
	void Name(std::string newName) {
		if (newName.size() > 0 && newName.size() < 32)
			name_ = newName;
	}

private:
	int age_;
	std::string name_;
};

