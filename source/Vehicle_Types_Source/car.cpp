#include "../../include/Vehicle_Types_Include/car.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Car::Car(const Time& entry_time, const LicensePlate& plate) : 
    Vehicle(FIRST_HOUR_COST, REGULAR_HOUR_COST, entry_time, plate) {}