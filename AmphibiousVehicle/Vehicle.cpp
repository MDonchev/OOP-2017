#include "Vehicle.h"

#include <iostream>
#include <cstring>

Vehicle::Vehicle(const char* _name, double _height, double _weight) : name(NULL)
{
    setName(_name);
    setHeight(_height);
    setWeight(_weight);
}
Vehicle::Vehicle(const Vehicle& other)
    : Vehicle(other.getName(),other.getHeight(),other.getWeight()) {}
Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        setName(other.getName());
        setHeight(other.getHeight());
        setWeight(other.getWeight());
    }
    return *this;
}
Vehicle::~Vehicle()
{
    delete[] name;
}
void Vehicle::setName(const char* _name)
{
    if (!_name) return;
    delete[] name;
    this->name = new char[strlen(_name) + 1];
    strcpy(name,_name);
}
void Vehicle::setHeight(double _height)
{
    height = (_height >= 0.0) ? _height : 0.0;
}
void Vehicle::setWeight(double _weight)
{
    weight = (_weight >= 0.0) ? _weight : 0.0;
}

bool Vehicle::canPassUnderBridge(double _bridge) const
{
    return height < _bridge;
}
bool Vehicle::canPassOverBridge(double _weight) const
{
    return weight < _weight;
}
