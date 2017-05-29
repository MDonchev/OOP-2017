#ifndef WATERVEHICLE_H
#define WATERVEHICLE_H

#include "Vehicle.h"

class WaterVehicle : virtual public Vehicle
{
    public:
        WaterVehicle(const char* = "", double = 0.0, double = 0.0, double = 0.0);
        //system copy constructor, operator= and destructor will be created
        double getMaxSpeed() const
        {
            return maxKnotSpeed;
        }

        double getSpeedUpStream(double) const;
        double getSpeedDownStream(double) const;
        double getTimeUpStream(double,double) const;
        double getTimeDownStream(double,double) const;

        void print() const;

    protected:
        void printOwn() const;
    private:
        double maxKnotSpeed;

};
#endif // WATERVEHICLE_H
