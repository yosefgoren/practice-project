#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "vehicle.h"

namespace MtmParkingLot
{
    class Motorbike : public Vehicle
    {
    public:
        Motorbike(const ParkingLotUtils::Time& entry_time, const LicensePlate& plate);
    private:
        static const int FIRST_HOUR_COST = 10;
        static const int REGULAR_HOUR_COST = 5;
    };
}

#endif