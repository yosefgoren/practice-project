#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <string>
#include <memory>
#include <exception>
#include <utility>
//template <class T>
typedef std::string Vehicle;


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

    class Block 
    //class Block<Vehicle> : public std::map<int, const Vehicle>
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

}

#endif