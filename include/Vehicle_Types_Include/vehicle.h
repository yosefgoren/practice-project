#ifndef VEHICLE_H
#define VEHICLE_H

#include "../Time.h"
#include "../ParkingLotTypes.h"

namespace MtmParkingLot 
{
    class Vehicle
    {
    public:
        Vehicle(ParkingLotUtils::Time entry_time, LicensePlate plate);
        virtual 

        ParkingLotUtils::Time getEntryTime() const;
        virtual unsigned int claculateBill(const ParkingLotUtils::Time& time) const;
        LicensePlate licensePlate() const;
        bool checkAndGiveFine(const ParkingLotUtils::Time& current_time);
        bool operator<(const Vehicle& vehicle) const;

    private:
        int first_hour;
        int regular_hour;
        static const unsigned int FINE_COST = 250;
        static const int HOURS_IN_DAY = 24;

        ParkingLotUtils::Time entry_time;
        bool got_fine = false;
        LicensePlate plate;
    };
}

#endif