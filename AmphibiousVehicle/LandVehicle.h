#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include "Vehicle.h"

class LandVehicle : virtual public Vehicle
{
    public:
        LandVehicle(const char* = "", const char* = "", double = 0.0, double = 0.0, unsigned = 0, double = 0.0);
        LandVehicle(const LandVehicle&);
        LandVehicle& operator=(const LandVehicle&);
        ~LandVehicle();

        const char* getModel() const
        {
            return model;
        }
        unsigned getMaxSpeed() const
        {
            return maxSpeed;
        }
        double getHorsePower() const
        {
            return horsePower;
        }

        double getTimePerKilometers(double) const;

        void print() const;

    protected:
        //function, that prints out only model,maxSpeed and horsePower
        void printOwn() const;

    private:
        char* model;
        unsigned maxSpeed;
        double horsePower;

        void setModel(const char*);
        void setHorsePower(double);

};
#endif // LANDVEHICLE_H
