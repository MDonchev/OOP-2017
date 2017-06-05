#include <iostream>
#include <cstring>
#include "FSObject.h"


void FSObject::setName(const char* _name)
{
    if (!_name || strlen(_name) == 0)
        return;
    delete name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name,_name);
}
FSObject::FSObject(const char* _name) : name(NULL)
{
    setName(_name);
}
FSObject::FSObject(const FSObject& other)
                : FSObject(other.name) {}
FSObject& FSObject::operator=(const FSObject& other)
{
    if (this != &other)
    {
        setName(other.name);
    }
    return *this;
}
FSObject::~FSObject()
{
    delete name;
}
const char* FSObject::getName() const
{
    return this->name;
}
void FSObject::print() const
{
    std::cout<<getName();
}
