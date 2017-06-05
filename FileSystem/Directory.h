#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FSObject.h"

class Directory : public FSObject
{
    public:
        Directory(const char*);
        Directory(const Directory&);
        Directory& operator=(const Directory&);
        ~Directory();

        //pure virtual functions in FSObject would be overridden
        virtual double getSize() const;
        virtual FSObject* clone() const;

        bool addElement(const FSObject&);

        virtual void print() const;
    private:
        FSObject** objectList;
        unsigned countObjects;

        void copyObjects(FSObject**, unsigned);
        void deleteObjects();
};
#endif // DIRECTORY_H
