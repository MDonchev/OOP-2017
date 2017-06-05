#include <iostream>

#include "Directory.h"

const unsigned MAX_ELEMENTS = 20;

void Directory::copyObjects(FSObject** objectL, unsigned _cntObj)
{
    this->objectList = new FSObject*[MAX_ELEMENTS];

    this->countObjects = (_cntObj > MAX_ELEMENTS) ? MAX_ELEMENTS : _cntObj;
    for (unsigned i = 0; i < countObjects ; i++)
    {
        this->objectList[i] = objectL[i]->clone();
    }
}
void Directory::deleteObjects()
{
    for(unsigned i = 0; i<this->countObjects; i++)
        delete objectList[i];
    delete[] objectList;
}
Directory::Directory(const char* _name) : FSObject(_name), countObjects(0)
{
    objectList = new FSObject*[MAX_ELEMENTS]{NULL};
}
Directory::Directory(const Directory& other) : FSObject(other), countObjects(other.countObjects)
{
    this->copyObjects(other.objectList, other.countObjects);
}
Directory& Directory::operator=(const Directory& other)
{
    if (this != &other)
    {
        FSObject::operator=(other);
        deleteObjects();
        copyObjects(other.objectList,other.countObjects);
    }
    return *this;
}
Directory::~Directory()
{
    deleteObjects();
}
//pure virtual functions override
double Directory::getSize() const
{
    double sum = 0;
    for(unsigned i = 0; i < countObjects; i++)
        sum += objectList[i]->getSize();
    return sum;
}
FSObject* Directory::clone() const
{
    //create dynamic copy of the Object
    return new Directory(*this);
}

bool Directory::addElement(const FSObject& element)
{
    //check whether there is empty space in the directory
    if (countObjects == MAX_ELEMENTS)
    {
        std::cout<<"Directory is full. Can not add!"<<std::endl;
        return false;
    }
    objectList[countObjects] = element.clone();
    countObjects++;
    return true;
}
void Directory::print() const
{
    std::cout << "<DIR> ";
	FSObject::print();

	std::cout << std::endl;
	for(size_t i = 0; i < this->countObjects; ++i)
	{
		std::cout << '\t';
		this->objectList[i]->print();
	}
	std::cout<<std::endl;
}
