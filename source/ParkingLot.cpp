#include "../include/ParkingLot.h"

using namespace MtmParkingLot;
using namespace ParkingLotUtils;

ParkingLot::ParkingLot(unsigned int parkingBlockSizes[]) :
    bike_block(parkingBlockSizes[0]),
    handicapped_block(parkingBlockSizes[1]),
    car_block(parkingBlockSizes[2])
{}

MtmParkingLot::ParkingResult ParkingLot::enterParking(ParkingLotUtils::VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime)
{
    switch (vehicleType)
    {
    case MOTORBIKE:
    break;

    case HANDICAPPED:
        handicapped_block.park(Handicapped(entranceTime, licensePlate));
    break;

    case CAR:
        car_block.park(Car(entranceTime, licensePlate));
        break;
    }

    return SUCCESS;
}

MtmParkingLot::ParkingResult exitParking(LicensePlate licensePlate, Time exitTime)
{
    
}


