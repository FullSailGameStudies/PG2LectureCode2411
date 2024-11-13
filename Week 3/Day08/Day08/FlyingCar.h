#pragma once
#include "Car.h"
class FlyingCar : public Car  //a FlyingCar IS-A Car
{
	//IF not provided, the compiler will provide a default ctor
public:

	FlyingCar(int year, std::string make, std::string model,
		      float maxAirSpeed, float maxAltitude) :
		//call the base ctor
		Car(year,make,model),
		airSpeed_(0),
		maxAirSpeed_(maxAirSpeed),
		altitude_(0),
		maxAltitude_(maxAltitude)
	{
	}

private:
	//fields (data)

	// a FlyingCar HAS-A airspeed, altitude, ...  (composition)
	// favor COMPOSITION (has-a) over Inheritance (is-a)  -- improves flexibility of the code
	float airSpeed_, maxAirSpeed_;
	float altitude_, maxAltitude_;

};

