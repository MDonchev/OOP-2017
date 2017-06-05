#ifndef FILE_H
#define FILE_H

#include "FSObject.h"

class File : public FSObject
{
    public:
        File(const char*, const char*, double);
        File(const File&);
        File& operator=(const File&);
        ~File();

        //pure virtual functions in FSObject would be overridden
        virtual double getSize() const;
        virtual FSObject* clone() const;

        const char* getExt() const;
        void setExt(const char*);
        void setSize(double);


        virtual void print() const;
    private:
        char* ext;
        double size;
};
#endif // FILE_H
