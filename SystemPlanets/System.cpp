#include <iostream>
#include <cmath>
#include <cstring>
#include "System.h"
const float PI = 3.14;
void System::setName(const char* _name)
{
    delete[] name;
    this->name = new char [strlen(_name) + 1];
    strcpy(name, _name);
}
void System::copySystem(const System& other)
{
    setName(other.setName());
    planets = new Planet [capacity];
    for (int i = 0; i<counter ; i++)
    {
        planets[i] = *(other.getPlanets() + i);
    }
}
void System::resizing()
{
    capacity *= 2;
    Planet* buffer = new Planet [capacity];
    for (int i = 0; i < counter ; i++)
        buffer[i] = planets[i];
    delete[] planets;
    planets = buffer;
}
void System::erasing()
{
    delete[] name;
    delete[] planets;
}
void System::addPlanet(const Planet& pl)
{
    if (capacity == 0) resizing();
    planets[counter] = pl;
    counter++;
    capacity--;
}
void System::remPlanet(const char* plName)
{
    //TODO
    for(int i=0; i<counter; i++)
    {
        if (strcmp(planets[i].getName(), plName) == 0)
        {
            for(int j=i; )
        }
    }
}
System::System(const char* _name, int _capacity = 1) : name(NULL), planets(NULL), capacity(_capacity), counter(0)
{
    setName(_name);
    planets = new Planet [_capacity];
}
System::System(const System& other) : name(NULL), planets(NULL), counter(other.getCounter()), capacity(other.getCapacity())
{
    erasing();
    copySystem(other);
}
System& System::operator=(const System& other)
{
    if (this != &other)
    {
        erasing();
        copySystem(other);
    }
    return *this;
}
System::~System()
{
    erasing();
}
Planet* System::biggestPlanet() const
{
    int indexBiggest = 0;
    float rad = planets[0].getDiam() / 2;
    float maxSize = (4*rad*rad*rad*PI)/3;
    for(int i=1; i<counter; i++)
    {
        float radHelp = planets[i].getDiam() / 2;
        float currSize = (4*radHelp*radHelp*radHelp*PI)/3;
        if (maxSize < currSize)
        {
            indexBiggest = i;
            maxSize = currSize;
        }
    }
    return planets + indexBiggest;
}
Planet* System::largestDist() const
{
    int indexLargeDist = 0;
    float maxDist = sqrt (planets[0].getPositon().x * planets[0].getPositon().x +
                          planets[0].getPositon().y * planets[0].getPositon().y +
                          planets[0].getPositon().z * planets[0].getPositon().z);

    for(int i=1; i<counter; i++)
    {
        float currDist = sqrt (planets[i].getPositon().x * planets[i].getPositon().x +
                              planets[i].getPositon().y * planets[i].getPositon().y +
                              planets[i].getPositon().z * planets[i].getPositon().z);
        if (maxDist < currDist)
        {
            indexLargeDist = i;
            maxDist = currDist;
        }
    }
    return planets + indexLargeDist;
}
void System::print() const
{
    std::cout<<name<<" :"<<std::endl;
    for (int i=0; i<counter; i++)
    {
        planets[i].print();
    }
}
