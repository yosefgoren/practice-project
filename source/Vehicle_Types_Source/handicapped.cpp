#include "../../include/Vehicle_Types_Include/handicapped.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Handicapped::Handicapped(const Time& entry_time, const LicensePlate& plate) : 
    Vehicle(FIRST_HOUR_COST, REGULAR_HOUR_COST, entry_time, plate) {}