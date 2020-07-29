#ifndef BLOCK_H
#define BLOCK_H

#include <map>
#include <string>
#include <memory>
#include <exception>
#include <utility>
#include "ParkingLotTypes.h"
#include "ParkingLotPrinter.h"
#include "ParkingSpot.h"


//typedef std::string Vehicle;


namespace MtmParkingLot
{
    // enum ParkingResult 
    // {
    //     SUCCESS,
    //     NO_EMPTY_SPOT,
    //     VEHICLE_NOT_FOUND,
    //     VEHICLE_ALREADY_PARKED,
    //     SPOT_TAKEN
    // };
    
    template <class Vehicle>
    class Block : public std::map<int, const Vehicle>
    {
    public:
        Block(std::size_t max_size) : max_size(max_size) {}
        ParkingLotUtils::ParkingResult park(const Vehicle& vehicle, ParkingLotUtils::VehicleType vehicle_type); 
        ParkingLotUtils::ParkingResult exit(const Vehicle& vehicle);
        int getSpot(const Vehicle& vehicle) const; //ParkingLotUtils::LicensePlate& plate) const;//new added by joseph
        bool contains(const Vehicle& vehicle) const;//ParkingLotUtils::LicensePlate& plate) const;//new added by joseph


        const Vehicle& operator[](int spot) const;
        Vehicle& operator[](int spot);

    private:
        //static const int AVAILABLE_SPOT = -1;
        void insert(const Vehicle& vehicle, int spot);
        void erase(const Vehicle& vehicle);
        int getEmptySpot();
        std::size_t size = 0;
        std::size_t max_size;
        std::map<int, Vehicle> spots;
        std::map<Vehicle, int> vehicles;

    };

    template <class Vehicle>
    static bool equiv(Vehicle vehicle, Vehicle other_vehicle)
    {
        return !(vehicle < other_vehicle) && !(other_vehicle < vehicle);
    }

    template <class Vehicle>
    int Block<Vehicle>::getSpot(const Vehicle& vehicle) const //ParkingLotUtils::LicensePlate& plate) const//new added by joseph
    {
        for(int i = 0; i < (int)max_size; ++i)
        {
            try
            {
                if(equiv(vehicle, operator[](i)))
                    return i;
            }
            catch (std::logic_error& e)
            {
                //this code is dumvb
            }
        }

        throw std::logic_error("No such vehilce...");
        return -1;
        //return VEHICLE_NOT_FOUND; this just returns 2
    }

    template <class Vehicle>
    bool Block<Vehicle>::contains(const Vehicle& vehicle) const //ParkingLotUtils::LicensePlate& plate) const
    {
        try
        {
            getSpot(vehicle);
        }
        catch (std::logic_error& e)
        {
            return false;
        }
        return true; //getSpot(plate) != VEHICLE_NOT_FOUND;
    } 


    template <class Vehicle>
    void Block<Vehicle>::insert(const Vehicle& vehicle, int spot)
    {
        spots.insert({spot, vehicle});
        vehicles.insert({vehicle, spot}); //need operator<()
        size++;
    }

    template <class Vehicle>
    void Block<Vehicle>::erase(const Vehicle& vehicle)
    {
        int spot = vehicles.find(vehicle)->second;
        spots.erase(spot);
        vehicles.erase(vehicle);
        size--;

    }

    template <class Vehicle>
    ParkingLotUtils::ParkingResult Block<Vehicle>::park(const Vehicle& vehicle, ParkingLotUtils::VehicleType vehicle_type)
    {
        if(size == max_size)
        {
            std::cout << ParkingLotUtils::ParkingLotPrinter::printEntryFailureNoSpot(std::cout).rdbuf() << std::endl;
            return ParkingLotUtils::NO_EMPTY_SPOT;
        }
        int spot = getEmptySpot();
        ParkingLotUtils::ParkingSpot parking_spot(vehicle_type, spot);

        if(vehicles.find(vehicle) != vehicles.end())
        {
            std::streambuf *buf = ParkingLotUtils::ParkingLotPrinter::printEntryFailureAlreadyParked(std::cout, parking_spot).rdbuf();
            std::cout << buf << std::endl;
            return ParkingLotUtils::VEHICLE_ALREADY_PARKED;
        }
        
        insert(vehicle, spot);
        std::streambuf *buf = ParkingLotUtils::ParkingLotPrinter::printEntrySuccess(std::cout, parking_spot).rdbuf();
        std::cout << buf << std::endl;
        return ParkingLotUtils::SUCCESS;
    }

    template <class Vehicle>
    ParkingLotUtils::ParkingResult Block<Vehicle>::exit(const Vehicle& vehicle)
    {
        if(vehicles.find(vehicle) == vehicles.end())
        {
            std::cout << ParkingLotUtils::ParkingLotPrinter::printExitFailure(std::cout).rdbuf() << std::endl;
            return ParkingLotUtils::VEHICLE_NOT_FOUND;
        }

        erase(vehicle);
        std::cout << ParkingLotUtils::ParkingLotPrinter::printExitSuccess(std::cout).rdbuf() << std::endl;
        return ParkingLotUtils::SUCCESS;
    }

    template <class Vehicle>
    int Block<Vehicle>::getEmptySpot()
    {
        for (int i = 0; i < int(max_size); ++i)
        {
            try
            {
                operator[](i);
            }
            catch(const std::logic_error& e)
            {
                return i;
            }
            
        }
        throw std::logic_error("No empty spot");
        return 0;
    }

    template <class Vehicle>
    const Vehicle& MtmParkingLot::Block<Vehicle>::operator[](int spot) const
    {
        if (spot == int(max_size))
        {
            throw std::out_of_range("Index out of range...");
        }
        typename std::map<int, Vehicle>::iterator data = spots.find(spot);
        if(data == spots.end())
        {
            throw std::logic_error("Empty spot...");
        }
        
        return data->second;
    }

        template <class Vehicle>
    Vehicle& MtmParkingLot::Block<Vehicle>::operator[](int spot)
    {
        if (spot == int(max_size))
        {
            throw std::out_of_range("Index out of range...");
        }

        typename std::map<int, Vehicle>::iterator data = spots.find(spot);
        if(data == spots.end())
        {
            throw std::logic_error("Empty spot...");
        }
        
        return data->second;
    }

}



#endif