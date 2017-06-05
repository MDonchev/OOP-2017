#ifndef FSOBJECT_H
#define FSOBJECT_H

class FSObject
{
    public:
        FSObject(const char*);
        FSObject(const FSObject&);
        FSObject& operator=(const FSObject&);
        //virtual destructor due to the objectList in Directory class
        virtual ~FSObject();

        //pure virtual functions
        virtual double getSize() const = 0;
        virtual FSObject* clone() const = 0;

        const char* getName() const;
        void setName(const char*);

        virtual void print() const;
    private:
        char* name;
};
#endif // FSOBJECT_H
