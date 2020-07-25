#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <string>
#include <memory>
#include <exception>
#include <utility>


//typedef std::string Vehicle;


namespace MtmParkingLot
{
    enum ParkingResult 
    {
        SUCCESS,
        NO_EMPTY_SPOT,
        VEHICLE_NOT_FOUND,
        VEHICLE_ALREADY_PARKED,
        SPOT_TAKEN
    };
    
    template <class Vehicle>
    class Block : public std::map<int, const Vehicle>
    {
    public:
        Block(std::size_t max_size) : max_size(max_size) {}
        ParkingResult park(Vehicle& vehicle, int spot); //const vehicle?
        ParkingResult exit(Vehicle& vehicle);

        const Vehicle& operator[](int spot);

    private:
        void insert(Vehicle& vehicle, int spot);
        void erase(Vehicle& vehicle);
        std::size_t size = 0;
        std::size_t max_size;
        std::map<int, Vehicle> spots;
        std::map<Vehicle, int> vehicles;

    };

    template <class Vehicle>
    void Block<Vehicle>::insert(Vehicle& vehicle, int spot)
    {
        spots.insert({spot, vehicle});
        vehicles.insert({vehicle, spot}); //need operator<()
        size++;
    }

    template <class Vehicle>
    void Block<Vehicle>::erase(Vehicle& vehicle)
    {
        int spot = vehicles.find(vehicle)->second;
        spots.erase(spot);
        vehicles.erase(vehicle);
        size--;

    }

    template <class Vehicle>
    ParkingResult Block<Vehicle>::park(Vehicle& vehicle, int spot)
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
        return SUCCESS;
    }

    template <class Vehicle>
    ParkingResult Block<Vehicle>::exit(Vehicle& vehicle)
    {
        if(vehicles.find(vehicle) == vehicles.end())
        {
            return VEHICLE_NOT_FOUND;
        }

        erase(vehicle);
        return SUCCESS;
    }

    template <class Vehicle>
    const Vehicle& MtmParkingLot::Block<Vehicle>::operator[](int spot)
    {
        typename std::map<int, Vehicle>::iterator data = spots.find(spot);
        if(data == spots.end())
        {
            throw std::out_of_range("Bad index...");
        }
        
        return data->second;
    }

}



#endif