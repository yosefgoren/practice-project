#include "../../include/Vehicle_Types_Include/motorbike.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Motorbike::Motorbike(const Time& entry_time, const LicensePlate& plate) : 
    Vehicle(FIRST_HOUR_COST, REGULAR_HOUR_COST, entry_time, plate) {}