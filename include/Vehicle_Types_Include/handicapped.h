#ifndef HANDICAPPED_H
#define HANDICAPPED_H

#include "vehicle.h"

namespace MtmParkingLot
{
    class Handicapped : public Vehicle
    {
    public:
        Handicapped(const ParkingLotUtils::Time& entry_time, const ParkingLotUtils::LicensePlate& plate);
    private:
        static const int FIRST_HOUR_COST = 15;
        static const int REGULAR_HOUR_COST = 0;
    };
}

#endif