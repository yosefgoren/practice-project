#include "../include/ParkingLot.h"
#include "../include/ParkingLotPrinter.h"

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

MtmParkingLot::ParkingResult ParkingLot::exitParking(LicensePlate plate, Time exitTime)
{
    if(bike_block.contains(Motorbike(Time(0,0,0),plate)))
    {
        bike_block.exit(bike_block[bike_block.getSpot(Motorbike(Time(0,0,0),plate))]);
        return SUCCESS;
    }
    if(handicapped_block.contains(Handicapped(Time(0,0,0),plate)))
    {
        handicapped_block.exit(handicapped_block[handicapped_block.getSpot(Handicapped(Time(0,0,0),plate))]);
        return SUCCESS;
    }
    if(car_block.contains(Car(Time(0,0,0),plate)))
    {
        car_block.exit(car_block[car_block.getSpot(Car(Time(0,0,0),plate))]);
        return SUCCESS;
    }

    ParkingLotUtils::ParkingLotPrinter::printExitFailure(std::cout, plate);
    return VEHICLE_NOT_FOUND;
}