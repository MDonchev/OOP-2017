#include "Vehicle.h"
#include "WaterVehicle.h"
#include <iostream>

WaterVehicle::WaterVehicle(const char* _name, double _height, double _weight, double _maxSpeed)
                    : Vehicle(_name,_height,_weight)
{
    this->maxKnotSpeed = (_maxSpeed > 0.0) ? _maxSpeed : 0.0;
}

double WaterVehicle::getSpeedUpStream(double stream) const
{
    return maxKnotSpeed - stream;
}
double WaterVehicle::getSpeedDownStream(double stream) const
{
    return maxKnotSpeed + stream;
}
double WaterVehicle::getTimeUpStream(double km, double stream) const
{
    double help = getSpeedUpStream(stream);
    if(help > 0.0)
    {
        return km/help;
    }
    return 0.0;
}
double WaterVehicle::getTimeDownStream(double km,double stream) const
{
    return km/getSpeedDownStream(stream);
}

void WaterVehicle::printOwn() const
{
    std::cout<<"Max Speed on water: "<<maxKnotSpeed<<std::endl;
}
void WaterVehicle::print() const
{
    Vehicle::print();
    printOwn();
}
