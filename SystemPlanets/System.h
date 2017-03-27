#ifndef SYSTEM_H
#define SYSTEM_H

#include "Planet.cpp"
class System
{
    public:
        System(const char*, int); //
        System(const System&); //
        System& operator= (const System&); //
        ~System(); //

        int getCapacity() const { return capacity; }
        int getCounter() const { return counter; }
        const char* getName() const { return name;}
        Planet* getPlanets() const { return planets;}

        void setName(const char*); //
        Planet* biggestPlanet() const; //
        Planet* largestDist() const; //
        void print() const; //

        void addPlanet(const Planet& pl);
        void remPlanet(const char* plName);

    private:
        void resizing(); //
        void copySystem(const System&); //
        void erasing (); //

        char* name;
        Planet* planets;
        int capacity;
        int counter;
};

#endif // SYSTEM_H
