#pragma once
enum Materials
{
	Wood,Iron,Stone,Obsidian,Titanium
};
class Sword
{
	//DESCRIBE (Data)
	// material, double-bladed, length, weight, sharpness

	//DO (Methods)
	//attack, block

public://EVERYONE can access it

	//ctor (constructor)
	//they initialize objects (give values to the fields)
	// IF you do not create a ctor, the compiler will give you a default ctor
	// IF you create a ctor, the compiler does NOT give you a default ctor
	Sword(Materials mat=Materials::Wood, float length=1.0f, bool dbleBladed=true);

	//getters (accessors)
	float GetLength() const {
		return length_;
	}
	float Sharpness() const { return sharpness_; }
	bool DoubleBladed() const { return doubleBladed_; }
	Materials Material() const { return material_; }

	//setters (mutators)
	void SetLength(float length)
	{
		if (length > 0.5f && length < 4.5f)//the protection
		{
			length_ = length;
		}
	}
	void Sharpness(float sharpness)
	{
		if (sharpness > 0 && sharpness <= 1)
		{
			sharpness_ = sharpness;
		}
	}
	void DoubleBladed(bool doubleBladed)
	{
		doubleBladed_ = doubleBladed;
	}
	
private://(DEFAULT) ONLY sword can access
	//camelCaseNamingConvention_
	float length_;
	float sharpness_;
	bool doubleBladed_;
	Materials material_;

protected://sword and all descendent classes can access

};
