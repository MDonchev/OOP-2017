#include "LandVehicle.h"

#include <iostream>
#include <cstring>

LandVehicle::LandVehicle(const char* _name, const char* _model, double _height,
                        double _weight, unsigned _max, double _horse)
                        : Vehicle(_name,_height,_weight),model(NULL), maxSpeed(_max)
{
    setModel(_model);
    setHorsePower(_horse);
}
LandVehicle::LandVehicle(const LandVehicle& other)
              : Vehicle(other),
                model(NULL),
                maxSpeed(other.getMaxSpeed()), horsePower(other.getHorsePower())
{
    setModel(other.getModel());
}
LandVehicle& LandVehicle::operator=(const LandVehicle& other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
        setModel(other.getModel());
        horsePower = other.getHorsePower();
        maxSpeed = other.getMaxSpeed();
    }
    return *this;
}
LandVehicle::~LandVehicle()
{
    delete[] model;
}


void LandVehicle::setModel(const char* _model)
{
    if (!_model) return;
    delete[] model;
    this->model = new char[strlen(_model) + 1];
    strcpy(this->model, _model);
}
void LandVehicle::setHorsePower(double _horse)
{
    this->horsePower = (_horse >= 0.0) ? _horse : 0.0;
}

double LandVehicle::getTimePerKilometers(double kilometers) const
{
    return kilometers/maxSpeed;
}

void LandVehicle::printOwn() const
{
    std::cout<<"Model: "<<model<<std::endl;
    std::cout<<"Max Speed on land: "<<maxSpeed<<std::endl;
    std::cout<<"Horse Powers: "<<horsePower<<std::endl;
}
void LandVehicle::print() const
{
    Vehicle::print();
    printOwn();
}
