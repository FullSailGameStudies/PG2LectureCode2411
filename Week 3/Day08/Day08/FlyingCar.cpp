#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
    //do I want to EXTEND the base version
    //or do I want to IGNORE (full override) the base version?

    //call the base method to EXTEND
    std::string baseInfo = Car::vehicleInformation();
    std::string derivedInfo = "\n Max Altitude: " + std::to_string(maxAltitude_) +
        "\t Max Airspeed: " + std::to_string(maxAirSpeed_);
    return baseInfo + derivedInfo;
}
