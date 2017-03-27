#include <iostream>
#include "System.cpp"
int main ()
{
    Position posMars = {3.0,3.0,3.0};
    Position posMercury = {1.0,1.0,1.0};
    Position posJupiter = {4.0,4.0,4.0};
    Position posEarth = {2.0,2.0,2.0};

    //Planet test;
    //test.print();
    Planet earth("Earth", posEarth, 400.00);
    //earth.print();

    //std::cout<<std::endl;
    //Planet copyEarth(earth);
    //std::cout<<std::endl;
    //copyEarth.print();


    Planet mars("Mars", posMars, 300);
    Planet mercury("Mercury", posMercury, 100);
    Planet jupiter("Jupiter", posJupiter, 1000);

    //mars.print();

    //std::cout<<std::endl;
    //Planet copyMars = mars;
    //copyMars.print();

    //copyEarth = mars;
    //std::cout<<std::endl;
    //copyEarth.print();
    //std::cout<<earth.distance(mars)<<std::endl;
    //std::cout<<mars.distance(earth)<<std::endl;
    System Solar("Solar System", 6);
    //std::cout<<"Created System"<<std::endl;
    Solar.addPlanet(earth);
    Solar.addPlanet(jupiter);
    Solar.addPlanet(mars);
    Solar.addPlanet(mercury);
    std::cout<<"Added planets"<<std::endl;
    System copySolar = Solar;
    //Solar.print();
    //std::cout<<copySolar.getCounter()<<std::endl;
    copySolar.print();
    return 0;
}

