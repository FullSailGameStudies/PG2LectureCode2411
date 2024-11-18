#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::Serialize(std::ostream& outstream, char delim) const
{
	outstream << mModelYear << delim << mMake << delim << mModel;
}

void Car::Deserialize(const std::string& csvData, char delim)
{
	std::stringstream carStream(csvData);
	std::string data;
	std::getline(carStream, data, delim);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delim);
	std::getline(carStream, mModel, delim);
}
