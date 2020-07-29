#include "../include/ParkingLot.h"
#include "../include/ParkingLotPrinter.h"

using namespace MtmParkingLot;
using namespace ParkingLotUtils;

ParkingLot::ParkingLot(unsigned int parkingBlockSizes[]) :
    bike_block(parkingBlockSizes[0]),
    handicapped_block(parkingBlockSizes[1]),
    car_block(parkingBlockSizes[2])
{}

ParkingResult ParkingLot::enterParking(ParkingLotUtils::VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime)
{
    ParkingResult result;
    int spot = -1;
    switch (vehicleType)
    {
        case MOTORBIKE:
        {
            Motorbike motorbike(entranceTime, licensePlate);
            result = bike_block.park(motorbike);
            spot = bike_block.getSpot(motorbike);
            break;
        }

        case HANDICAPPED:
        {
            Handicapped handicapped(entranceTime, licensePlate);
            result = handicapped_block.park(handicapped);
            spot = handicapped_block.getSpot(handicapped);
            break;
        }

        case CAR:
        {
            Car car(entranceTime, licensePlate);
            result = car_block.park(car);
            spot = car_block.getSpot(car);
            break;
        }
    }

    if (result == SUCCESS)
    {
        std::cout << ParkingLotPrinter::printEntrySuccess(std::cout, ParkingSpot(vehicleType, spot)).rdbuf() << std::endl;
        return SUCCESS;
    }
    else if (result == VEHICLE_ALREADY_PARKED)
    {
        std::cout << ParkingLotPrinter::printEntryFailureAlreadyParked(std::cout, ParkingSpot(vehicleType, spot)).rdbuf() << std::endl;
    }

    return result;
}

ParkingResult ParkingLot::exitParking(LicensePlate plate, Time exitTime)
{
    //std::cout << ParkingLotPrinter::printVehicle(std::cout, )
    ParkingResult result = VEHICLE_NOT_FOUND;
    VehicleType vehicle_type;
    Time entrance_time;
    int spot = -1;
    int bill = -1;
    
    if(bike_block.contains(Motorbike(Time(0,0,0),plate)))
    {
        spot = bike_block.getSpot(Motorbike(Time(0,0,0),plate));
        result = bike_block.exit(bike_block[spot]);
        entrance_time = bike_block[spot].getEntryTime();
        bill = bike_block[spot].claculateBill(exitTime);
        vehicle_type = MOTORBIKE;
    }
    if(handicapped_block.contains(Handicapped(Time(0,0,0),plate)))
    {
        spot = handicapped_block.getSpot(Handicapped(Time(0,0,0),plate));
        result = handicapped_block.exit(handicapped_block[spot]);
        entrance_time = handicapped_block[spot].getEntryTime();
        bill = handicapped_block[spot].claculateBill(exitTime);
        vehicle_type = HANDICAPPED;
    }
    if(car_block.contains(Car(Time(0,0,0),plate)))
    {
        spot = car_block.getSpot(Car(Time(0,0,0),plate));
        result = car_block.exit(car_block[spot]);
        entrance_time = car_block[spot].getEntryTime();
        bill = car_block[spot].claculateBill(exitTime);
        vehicle_type = CAR;
    }

    std::cout << ParkingLotPrinter::printVehicle(std::cout, vehicle_type, plate, entrance_time).rdbuf() << std::endl;

    if (result == SUCCESS)
    {
        std::cout << ParkingLotPrinter::printExitSuccess(std::cout, ParkingSpot(vehicle_type, spot), exitTime, bill).rdbuf() << std::endl;
        return SUCCESS;
    }

    ParkingLotUtils::ParkingLotPrinter::printExitFailure(std::cout, plate);
    return VEHICLE_NOT_FOUND;
}