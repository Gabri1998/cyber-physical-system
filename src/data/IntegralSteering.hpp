#ifndef INTEGRAL_STEERING_HPP
#define INTEGRAL_STEERING_HPP

#include <iostream>

float integralSteering(float leftVoltage, float rightVoltage, float frontDistance, float gsrBefore);
float frontSteer(float frontDistance);
float sideSteer(float leftVoltage, float rightVoltage, float gsrBefore);

#endif