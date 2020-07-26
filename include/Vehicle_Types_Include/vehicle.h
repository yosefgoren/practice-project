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
        virtual unsigned int claculateBill(const ParkingLotUtils::Time& time) const;
        ParkingLotUtils::LicensePlate licensePlate() const;
        bool checkAndGiveFine(const ParkingLotUtils::Time& current_time);
        bool operator<(const Vehicle& vehicle) const;
        
        //debug tools:
        bool gotFine()
        {
            return got_fine;
        }
    
    protected:
        Vehicle(int first_hour, int regular_hour, const ParkingLotUtils::Time& entry_time, const ParkingLotUtils::LicensePlate& plate);

    private:
        static const unsigned int FINE_COST = 250;
        static const unsigned int MAX_HOURS = 6;
        static const int HOURS_IN_DAY = 24;
        
        int first_hour;
        int regular_hour;
        ParkingLotUtils::Time entry_time;
        bool got_fine = false;
        ParkingLotUtils::LicensePlate plate;
    };
}

#endif