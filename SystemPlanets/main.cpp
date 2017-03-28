#include <iostream>
#include "System.cpp"
int main ()
{
    Position posMars = {3.0,3.0,3.0};
    Position posMercury = {1.0,1.0,1.0};
    Position posJupiter = {4.0,4.0,4.0};
    Position posEarth = {2.0,2.0,2.0};

    Planet earth("Earth", posEarth, 400.00);
    Planet mars("Mars", posMars, 300);
    Planet mercury("Mercury", posMercury, 100);
    Planet jupiter("Jupiter", posJupiter, 1000);

    System Solar("Solar System");

    Solar.addPlanet(earth);
    Solar.addPlanet(jupiter);
    Solar.addPlanet(mars);
    Solar.addPlanet(mercury);
    Solar.print();

    std::cout<<std::endl;
    std::cout<<std::endl;
    Solar.biggestPlanet()->print();
    std::cout<<std::endl;
    std::cout<<std::endl;
    Solar.largestDist()->print();
    Position neptunPos = {7,7,7};
    Position plytoPos = {9,9,9};
    Planet neptun ("Neptun", neptunPos, 700);
    Planet plyto("Plyto", plytoPos, 50);
    Solar.addPlanet(neptun);
    Solar.addPlanet(plyto);
    std::cout<<std::endl;
    Solar.print();
    std::cout<<std::endl;
    std::cout<<std::endl;
    Solar.remPlanet("Jupiter");
    Solar.print();
    std::cout<<std::endl;
    std::cout<<std::endl;
    Solar.biggestPlanet()->print();
    std::cout<<std::endl;
    std::cout<<std::endl;
    Solar.largestDist()->print();
    return 0;
}

