#include "../../include/Vehicle_Types_Include/vehicle.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Time Vehicle::getEntryTime() const
{
    return entry_time;
}

unsigned int Vehicle::bill() const
{
    return current_bill;
}

LicensePlate Vehicle::licensePlate() const
{
    return plate;
}

bool Vehicle::checkAndGiveFine(const Time& current_time)
{
    if((current_time-entry_time).toHours() > HOURS_IN_DAY)
    {
        current_bill += FINE_COST;
        return true;
    }

    return false;
}

bool Vehicle::operator<(const Vehicle& vehicle) const
{
    return plate  < vehicle.licensePlate();
}