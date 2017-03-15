#ifndef PLANET_H
#define PLANET_H
#include <iostream>
struct Position
{
    float x;
    float y;
    float z;
    void print () const;
    Position& operator= (const Position&);
};
class Planet
{
    public:
        Planet();
        Planet(const char*, Position, float);
        Planet(const Planet&);
        Planet& operator= (const Planet&);
        ~Planet();

        const char* getName () const
        {
            return this->name;
        }
        Position getPositon () const
        {
            return this->pos;
        }
        float getDiam () const
        {
            return this->diam;
        }

        float distance (const Planet&) const;

        void setName (const char*);
        void setPosition (const Position&);
        void setDiam (float);

        void print () const;


    private:
        //helper for copy constructor and operator=
        void copyPlanet (const Planet&);


    private:
        char* name;
        Position pos;
        float diam;

};


#endif // PLANET_H
