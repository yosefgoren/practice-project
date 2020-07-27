#ifndef MTMPARKINGLOT_PARKINGLOT_H
#define MTMPARKINGLOT_PARKINGLOT_H

#include "ParkingLotTypes.h"
#include "Time.h"
#include "ParkingSpot.h"
#include "Block.h"
#include "Vehicle_Types_Include/vehicle.h"
#include "Vehicle_Types_Include/motorbike.h"
#include "Vehicle_Types_Include/handicapped.h"
#include "Vehicle_Types_Include/car.h"

namespace MtmParkingLot {

    using namespace ParkingLotUtils;
    using std::ostream;

    class ParkingLot
    {
    public:

        ParkingLot(unsigned int parkingBlockSizes[]);
        ~ParkingLot() = default;
        ParkingResult enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime);
        ParkingResult exitParking(LicensePlate licensePlate, Time exitTime);//joseph
        ParkingResult getParkingSpot(LicensePlate licensePlate, ParkingSpot& parkingSpot) const;
        void inspectParkingLot(Time inspectionTime);//joseph
        friend ostream& operator<<(ostream& os, const ParkingLot& parkingLot);

    private:
        Block<MtmParkingLot::Motorbike> bike_block;
        Block<MtmParkingLot::Handicapped> handicapped_block;
        Block<MtmParkingLot::Car> car_block;
    };

}

#endif //MTMPARKINGLOT_PARKINGLOT_H
