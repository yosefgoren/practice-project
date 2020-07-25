#include "../../include/Vehicle_Types_Include/vehicle.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Vehicle::Vehicle(ParkingLotUtils::Time entry_time, LicensePlate plate) : 
    entry_time(entry_time), plate(plate) {}

Time Vehicle::getEntryTime() const
{
    return entry_time;
}

LicensePlate Vehicle::licensePlate() const
{
    return plate;
}

bool Vehicle::checkAndGiveFine(const Time& current_time)
{
    if((current_time-entry_time).toHours() > HOURS_IN_DAY)
    {
        got_fine = true;
        return true;
    }

    return false;
}

bool Vehicle::operator<(const Vehicle& vehicle) const
{
    return plate  < vehicle.licensePlate();
}