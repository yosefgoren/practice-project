#include "../include/Block.h"

void MtmParkingLot::Block::insert(Vehicle& vehicle, int spot)
{
    spots.insert({spot, vehicle});
    vehicles.insert(vehicle, spot); //need operator<()
}
void MtmParkingLot::Block::erase(Vehicle& vehicle)
{
    int spot = vehicles.find(vehicle);
    spots.erase(spot);
    vehicles.erase(vehicle);
    size--;

}
MtmParkingLot::ParkingResult MtmParkingLot::Block::park(Vehicle& vehicle, int spot)
{
    if(size == max_size)
    {
        return NO_EMPTY_SPOT;
    }

    if(vehicles.find(vehicle) != vehicles.end())
    {
        return VEHICLE_ALREADY_PARKED;
    }

    if(spots.find(spot) != spots.end())
    {
        return SPOT_TAKEN;
    }

    insert(vehicle, spot);

}

MtmParkingLot::ParkingResult MtmParkingLot::Block::exit(Vehicle& vehicle)
{
    if(vehicles.find(vehicle) == vehicles.end())
    {
        return VEHICLE_NOT_FOUND;
    }

    erase(vehicle);
}

const Vehicle& MtmParkingLot::Block::operator[](int spot)
{
    std::map<int, Vehicle>::iterator data = spots.find(spot);
    if(data == spots.end())
    {
        throw std::out_of_range("Bad index...");
    }
    
    return data->second;
}