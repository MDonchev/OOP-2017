#include <iostream>
#include <cstring>
#include <cmath>
#include "Planet.h"
void Position::print() const
{
    std::cout<<"("<<x<<","<<y<<","<<z<<")";
}
Position& Position::operator= (const Position& other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;

    return *this;
}
void Planet::setName (const char* nam)
{
    if (!nam)
    {
        delete[] this->name;
        this->name = NULL;
        return;
    }
    delete[] this->name;
    this->name = new char[strlen(nam)+1];
    strcpy(this->name,nam);
}
void Planet::setDiam(float diam)
{
    this->diam = diam;
}
void Planet::setPosition(const Position& position)
{
    this->pos = position;
}
void Planet::copyPlanet(const Planet& other)
{
    delete[] this->name;
    this->name = new char [strlen(other.getName())+1];
    strcpy(this->name,other.getName());
    this->pos = other.getPositon();
    this->diam = other.getDiam();
}
Planet::Planet() : name(NULL)
{
    setName("");
    this->pos.x = 0.0;
    this->pos.y = 0.0;
    this->pos.z = 0.0;
    setDiam(0.0);
}
Planet::Planet(const char* nameH, Position posH, float distH) : name(NULL)
{
    setName(nameH);
    setPosition(posH);
    setDiam(distH);
}
Planet::Planet(const Planet& other) : name(NULL)
{
    std::cout<<"CopyConstructor"<<std::endl;
    copyPlanet(other);
}
Planet& Planet::operator= (const Planet& other)
{
    std::cout<<"operator="<<std::endl;
    if (this != &other)
        copyPlanet(other);
    return *this;
}
Planet::~Planet()
{
    delete[] name;
}
float Planet::distance (const Planet& other) const
{
    float diffX,diffY,diffZ;
    diffX = this->pos.x - other.getPositon().x;
    diffY = this->pos.y - other.getPositon().y;
    diffZ = this->pos.z - other.getPositon().z;

    return (float)sqrt(diffX*diffX + diffY*diffY + diffZ*diffZ);
}
void Planet::print() const
{
    std::cout<<this->name<<" ";
    this->pos.print();
    std::cout<<" "<<this->diam<<std::endl;
}
