#include "Sword.h"

Sword::Sword(Materials mat, float length, bool dbleBladed) :
	material_(mat),
	//SetLength(length),
	doubleBladed_(dbleBladed),
	sharpness_(1.f)
{
	SetLength(length);
	//mat = material_;//WRONG! backwards
	//material_ = mat;
	//length_ = length;
	//doubleBladed_ = dbleBladed;
	//sharpness_ = 1.0f;
}
