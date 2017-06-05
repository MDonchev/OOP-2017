#include <iostream>
#include <cstring>

#include "File.h"

void File::setExt(const char* _ext)
{
    if(!_ext || strlen(_ext) == 0) return;

    delete ext;
    this->ext = new char[strlen(_ext) + 1];
    strcpy(this->ext,_ext);
}
void File::setSize(double _size)
{
    this->size = (_size >= 0.0) ? _size : 0.0;
}
File::File(const char* _name, const char* _ext, double _size)
                    : FSObject(_name), ext(NULL)
{
    setExt(_ext);
    setSize(_size);
}
File::File(const File& other) : FSObject(other), ext(NULL)
{
    setExt(other.ext);
    setSize(other.size);
}
File& File::operator=(const File& other)
{
    if(this != &other)
    {
        FSObject::operator=(other);

        setExt(other.ext);
        setSize(other.size);
    }
    return *this;
}
File::~File()
{
    delete ext;
}
const char* File::getExt() const
{
    return this->ext;
}

//pure virtual functions override
double File::getSize() const
{
    return this->size;
}
FSObject* File::clone() const
{
    //create dynamic copy of the Object
    return new File(*this);
}


void File::print() const
{
    FSObject::print();
    std::cout<<"."<<getExt()<<'\t'<<this->getSize()<<" MB"<<std::endl;
}
