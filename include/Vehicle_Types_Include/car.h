#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

namespace MtmParkingLot
{
    class Car : public Vehicle
    {
    public:
        Car(const ParkingLotUtils::Time& entry_time, const LicensePlate& plate);
    private:
        static const int FIRST_HOUR_COST = 20;
        static const int REGULAR_HOUR_COST = 10;
    };
}

#endif