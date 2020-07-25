#include "../../include/Vehicle_Types_Include/vehicle.h"

using namespace ParkingLotUtils;
using namespace MtmParkingLot;

Vehicle::Vehicle(int first_hour, int regular_hour, ParkingLotUtils::Time entry_time, LicensePlate plate) : 
    first_hour(first_hour), regular_hour(regular_hour), entry_time(entry_time), plate(plate) {}

Time Vehicle::getEntryTime() const
{
    return entry_time;
}

unsigned int Vehicle::claculateBill(const ParkingLotUtils::Time& time) const
{
    unsigned int bill = first_hour;
    //edge case: if entry and leave are in the same min, charge for an hour or nothing? - assumed charge for an hour.
    
    unsigned int hours_inside = (entry_time-time).toHours() < MAX_HOURS ? (entry_time-time).toHours() : MAX_HOURS;
    bill += hours_inside > 0 ? (hours_inside-1)*regular_hour : 0;

    return bill + int(got_fine)*FINE_COST;
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