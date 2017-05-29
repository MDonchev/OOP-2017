#include "AmphibiousVehicle.h"

#include <iostream>

AmphibiousVehicle::AmphibiousVehicle(const char* _name, const char* _model, double _height,
                                     double _weight, unsigned _maxLand, double _horse, double _maxWater)
                                     :   Vehicle(_name,_height,_weight),
                                         LandVehicle(_name,_model,_height,_weight,_maxLand,_horse),
                                         WaterVehicle(_name,_height,_weight,_maxWater) {}

void AmphibiousVehicle::print() const
{
    Vehicle::print();
    LandVehicle::printOwn();
    WaterVehicle::printOwn();
}
