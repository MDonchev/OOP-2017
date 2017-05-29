#include "Vehicle.h"
#include "LandVehicle.h"
#include "WaterVehicle.h"
#include "AmphibiousVehicle.h"

#include <iostream>
using namespace std;

// function which states if an amphibious vehicle
// would be able to pass through the path for 1 hour:
// Path:
// 1) 5 km on land
// 2) after that pass under a bridge - 5 m high
// 3) 5 km on water down the stream - 10 stream speed
bool canPassPath(const AmphibiousVehicle& amph)
{
    double time = amph.getTimePerKilometers(5);
    if (!amph.canPassUnderBridge(5))
    {
        return false;
    }

    time += amph.getTimeDownStream(5,10);
    cout<<"Time: "<<time<<endl;
    return time < 1;
}
int main()
{
    AmphibiousVehicle amphibia1("Amphibia 1","1", 3, 10, 80, 30, 15);
    amphibia1.print();
    AmphibiousVehicle amphibia2("Amphibia 2", "2", 2.50, 8, 60, 20, 10.3);

    cout<<endl;
    cout<<endl;
    cout<<endl;

    //demonstration of copy constructor and operator=
    {
        AmphibiousVehicle another = amphibia1;
        cout<<"////Copy Constructor////"<<endl;
        cout<<endl;
        another.print();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        another = amphibia2;
        cout<<"//// Operator = ////"<<endl;
        another.print();
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<canPassPath(amphibia1)<<endl;
    cout<<canPassPath(amphibia2)<<endl;

    return 0;
}
