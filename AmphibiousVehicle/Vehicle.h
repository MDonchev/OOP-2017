#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle
{
    public:
        Vehicle(const char* = "", double = 0.0, double = 0.0);
        Vehicle(const Vehicle&);
        Vehicle& operator=(const Vehicle&);
        ~Vehicle();

        const char* getName() const
        {
            return this->name;
        }
        double getHeight() const
        {
            return this->height;
        }
        double getWeight() const
        {
            return this->weight;
        }

        bool canPassUnderBridge(double) const;
        bool canPassOverBridge(double) const;

        void print() const
        {
            std::cout<<"Name: "<<name<<std::endl;
            std::cout<<"Height: "<<height<<std::endl;
            std::cout<<"Weight: "<<weight<<std::endl;
        }
    private:
        char* name;

        double weight;
        double height;

        void setName(const char*);
        void setWeight(double);
        void setHeight(double);
};


#endif // VEHICLE_H
