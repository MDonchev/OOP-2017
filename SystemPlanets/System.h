#ifndef SYSTEM_H
#define SYSTEM_H
class System
{
    public:
        System(const char*, int); //
        System(const System&);
        System& operator= (const System&);
        ~System();

        int getCapacity() const { return capacity; }
        int getCounter() const { return counter; }
        const char* getName() const { return name;}

        void setName(const char*); //
        Planet* biggestPlanet() const;
        Planet* largestPlanet() const;
        void print() const;

    private:
        bool resizing(); //
        void copySystem(const System&);
        void erasing ();

        char* name;
        Planet* planets;
        int capacity;
        int counter;
};

#endif // SYSTEM_H
