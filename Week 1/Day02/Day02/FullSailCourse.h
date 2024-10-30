#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:

	void FillGrades(std::vector<float>& grades);
	void ShowGrades(const std::vector<float>& grades);
	void Stats(const std::vector<float>& grades, float& min, float& max) const;

	const std::string& GetName() const;
	void SetName(const std::string& name) {
		if (name.size() > 0 && name.size() < 32)
			name_ = name;
	}

private:
	std::string name_;

};

