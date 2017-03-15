#include <iostream>
#include "Planet.cpp"
int main ()
{
    Position posMars = {1.0,2.0,4.0};
    Position posEarth = {4.0,7.0,2.0};

    Planet test;
    test.print();
    Planet earth("Earth", posEarth, 340.60);
    earth.print();

    std::cout<<std::endl;
    Planet copyEarth(earth);
    std::cout<<std::endl;
    copyEarth.print();


    Planet mars("Mars", posMars, 500);
    mars.print();

    std::cout<<std::endl;
    Planet copyMars = mars;
    copyMars.print();

    copyEarth = mars;
    std::cout<<std::endl;
    copyEarth.print();
    std::cout<<earth.distance(mars)<<std::endl;
    std::cout<<mars.distance(earth)<<std::endl;
    return 0;
}

