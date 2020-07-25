#ifndef VEHICLE_H
#define VEHICLE_H

#include "../Time.h"
#include "../ParkingLotTypes.h"

namespace MtmParkingLot 
{
    class Vehicle
    {
    public:

        ParkingLotUtils::Time getEntryTime() const;
        unsigned int bill() const;
        LicensePlate licensePlate() const;
        virtual void updateBill(const ParkingLotUtils::Time& current_time) = 0;
        bool checkAndGiveFine(const ParkingLotUtils::Time& current_time);
        bool operator<(const Vehicle& vehicle) const;

    private:
        static const unsigned int FINE_COST = 250;
        static const int HOURS_IN_DAY = 24;

        ParkingLotUtils::Time entry_time;
        unsigned int current_bill;
        LicensePlate plate;
    };
}

#endif