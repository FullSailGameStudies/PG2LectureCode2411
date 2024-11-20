#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Car
{
private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

public:
	std::string vehicleInformation();

	Car() :mModelYear(0), mMake(""), mModel("") { }
	Car(int modelYear, std::string make, std::string model) :
		mModelYear(modelYear), mMake(make), mModel(model)
	{}
	Car(const std::string& csvData, char delim)
	{
		Deserialize(csvData, delim);
	}

	/// <summary>
	/// Saves the object in CSV format
	/// </summary>
	/// <param name="outstream">the out stream to serialize to</param>
	/// <param name="delim">The delimiter to use to separate the data</param>
	void Serialize(std::ostream& outstream, char delim) const;

	/// <summary>
	/// Will deserialize the Car object from CSV format
	/// </summary>
	/// <param name="csvData">string of csv data. should contain year,make,model</param>
	/// <param name="delim">The csv separator</param>
	void Deserialize(const std::string& csvData, char delim);

	int ModelYear() const  //const says the method can't modify anything
	{ 
		return mModelYear;  //provides access to the field's value
	}

	void ModelYear(int modelYear)
	{
		mModelYear = modelYear;
	}

	const std::string& Make() const
	{
		return mMake;
	}
	void Make(std::string make)
	{
		mMake = make;
	}

	const std::string& Model() const
	{
		return mModel;
	}
	void Model(std::string model)
	{
		mModel = model;
	}
};

