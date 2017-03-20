#include <iostream>
#include <cstring>
#include "System.h"
void System::setName(const char* _name)
{
    delete[] name;
    this->name = new char [strlen(_name) + 1];
    strcpy(name, _name);
}
bool System::resizing()
{
    (capacity != 0) ? return true : capacity *= 2;
    Planet* buffer = new (std::nothrow) Planet [capacity];
    if (!buffer) {return false;}
    for (int i = 0; i < counter ; i++)
        buffer[i] = planets[i];
    delete[] planets;
    planets = buffer;
    return true;
}
void System::erasing()
{
    delete[] name;
    delete[] planets;
}
System::System(const char* _name, int _capacity = 1) : name(NULL), capacity(_capacity), counter(0)
{
    setName(_name);
    planets = new Planet [_capacity];
}
System::System(const System& other) : name(NULL), planets(NULL), counter(other.getCounter()), capacity(other.getCapacity())
{
    erasing();
    setName(other.setName());
    for (int i = 0; i<counter ; i++)
    {

    }
}
