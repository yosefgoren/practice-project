#include <iostream>
#include <string>

#include "include/Block.h"
#include "include/Time.h"
#include "include/ParkingLotTypes.h"//do we need this
#include "include/Vehicle_Types_Include/vehicle.h"
#include "include/Vehicle_Types_Include/car.h"
#include "include/Vehicle_Types_Include/handicapped.h"
#include "include/Vehicle_Types_Include/motorbike.h"

using std::cout;
using std::endl;

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

using MtmParkingLot::Car;
using MtmParkingLot::Handicapped;
using MtmParkingLot::Motorbike;

bool block_test_1();

int main()
{
    if(block_test_1())
    {
        cout << "test succesess!" << endl;
    }
    else
    {
        cout << "test failure!" << endl;
    }
    return 0;
}

bool block_test_1()
{
    MtmParkingLot::Block<Car> car_block(5);
    Time time_of_entry(0,0,0);
    Car my_sick_lambo(time_of_entry, string("yell0w"));
    car_block.park(my_sick_lambo, 2);

    cout << my_sick_lambo.licensePlate() << endl;

    // try
    // {
    //     cout << block[3] << endl;
    // }
    // catch (std::out_of_range& e)
    // {
    //     cout << e.what();
    // }

    // if (block[2] != std::string("hi"))
    // {
    //     return false;
    // }
    return true;
}