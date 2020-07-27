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
        ParkingResult park(const Vehicle& vehicle, int spot = AVAILABLE_SPOT); 
        ParkingResult exit(const Vehicle& vehicle);

        const Vehicle& operator[](int spot) const;
        Vehicle& operator[](int spot);

    private:
        static const int AVAILABLE_SPOT = -1;
        void insert(const Vehicle& vehicle, int spot);
        void erase(const Vehicle& vehicle);
        int getEmptySpot();
        std::size_t size = 0;
        std::size_t max_size;
        std::map<int, Vehicle> spots;
        std::map<Vehicle, int> vehicles;

    };

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
    ParkingResult Block<Vehicle>::park(const Vehicle& vehicle, int spot)
    {
        if(size == max_size)
        {
            return NO_EMPTY_SPOT;
        }

        if(vehicles.find(vehicle) != vehicles.end())
        {
            return VEHICLE_ALREADY_PARKED;
        }

        if(spot == AVAILABLE_SPOT)
        {
            try
            {
                spot = getEmptySpot();
            }
            catch(std::logic_error& e)
            {
                return NO_EMPTY_SPOT;
            }
        }
        else if (spot < AVAILABLE_SPOT || spot >= int(max_size))
        {
            throw std::logic_error("No such spot...");
        }

        if(spots.find(spot) != spots.end())
        {
            return SPOT_TAKEN;
        }
        

        insert(vehicle, spot);
        return SUCCESS;
    }

    template <class Vehicle>
    ParkingResult Block<Vehicle>::exit(const Vehicle& vehicle)
    {
        if(vehicles.find(vehicle) == vehicles.end())
        {
            return VEHICLE_NOT_FOUND;
        }

        erase(vehicle);
        return SUCCESS;
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