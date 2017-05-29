#ifndef AMPHIBIOUSVEHICLE_H
#define AMPHIBIOUSVEHICLE_H

#include "LandVehicle.h"
#include "WaterVehicle.h"

class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
    public:
        AmphibiousVehicle(const char* = "", const char* = "", double = 0.0,
                           double = 0.0, unsigned = 0, double = 0.0, double = 0.0);

        void print() const;
    private:
};
#endif // AMPHIBIOUSVEHICLE_H
