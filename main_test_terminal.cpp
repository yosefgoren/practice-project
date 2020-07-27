#include <functional>
#include <string>
#include <iostream>
#include <vector>

#include "include/Block.h"
#include "include/Time.h"
#include "include/ParkingLotTypes.h" //do we need this
#include "include/Vehicle_Types_Include/vehicle.h"
#include "include/Vehicle_Types_Include/car.h"
#include "include/Vehicle_Types_Include/handicapped.h"
#include "include/Vehicle_Types_Include/motorbike.h"

using std::cout;
using std::endl;

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

/* #region tests implementation  */
bool test_0()
{
    Block<Motorbike> back_yard(4);
    back_yard.park(Motorbike(Time(0,0,0), "BestB1keEver"), 2);

    Motorbike& bike_refrence = back_yard[2];

    if(bike_refrence.gotFine())
    {
        cout << "fine was given" << endl;
    }
    else
    {
        cout << "fine was not given" << endl;
    }

    bike_refrence.checkAndGiveFine(Time(1,23,60));

    if(bike_refrence.gotFine())
    {
        cout << "fine was given" << endl;
    }
    else
    {
        cout << "fine was not given" << endl;
    }

    return true;
}

bool test_1()
{
    Block<Car> car_block(5);
    Time time_of_entry(0, 0, 0);
    Car my_sick_lambo(time_of_entry, string("yell0w"));
    Car my_healthy_lambo(Time(0, 0, 2), string("hi"));

    cout << "Parking 2 cars @ parking spots #2 & #3 ... ";
    car_block.park(my_sick_lambo, 2);
    car_block.park(my_healthy_lambo, 3);
    cout << "OK" << endl;
    cout << "spot #2: " << car_block[2].licensePlate() << endl;
    cout << "spot #3: " << car_block[3].licensePlate() << endl;

    cout << "trying to park new car @ #2 ... ";
    if (int(car_block.park(Car(Time(0, 0, 2), string("h2i")), 2)) == int(ParkingLotUtils::SUCCESS)) 
    {
        return false;
    }
    else
    {
        cout << "spot is occupied." << endl;
    }

    cout << "kicking out car @ spot #2 ... ";
    car_block.exit(my_sick_lambo);
    cout << "OK" << endl;

    cout << "spot #2: ";
    try
    {
        cout << car_block[2].licensePlate() << endl;
    }
    catch (std::logic_error &e)
    {
        cout << e.what() << endl;
    }

    cout << "trying to park @ #2 an already-parked car @ #3 ... ";
    if (int(car_block.park(my_healthy_lambo, 2)) == int(ParkingLotUtils::SUCCESS))
    {
        return false;
    }
    else
    {
        cout << "Car already parked @ #3." << endl;
    }

    cout << "spot #2: ";
    try
    {
        cout << car_block[2].licensePlate() << endl;
    }
    catch (std::logic_error &e)
    {
        cout << e.what() << endl;
    }
    cout << "spot #3: " << car_block[3].licensePlate() << endl;

    if (car_block[3].licensePlate() != std::string("hi"))
    {
        return false;
    }
    else 
    {
        cout << "License plate of car @ #3 is \"hi\": " << car_block[3].licensePlate() << endl;
    }
    return true;
}

#define TRU true
bool test_2()
{
    return TRU;
}
#undef TRU
/* #endregion */

/* #region call and run tests  */

void run_test(std::function<bool()> test, std::string test_name)
{
    if (!test())
    {
        std::cout << test_name << " FAILED." << std::endl;
        return;
    }
    std::cout << test_name << " SUCCEEDED." << std::endl;
}

int main()
{
    std::vector<std::function<bool()>> tests{test_0, test_1, test_2};
    //std::function<bool()> tests[NUMBER_OF_TESTS]= {test_1,test_2,test_3,test_4,test_5,test_6};
    for (int i = 0; i < int(tests.size()); ++i)
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Running test #" << i << "..." << endl;
        run_test(tests[i], "Test " + std::to_string(i));
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return 0;
}
/* #endregion */