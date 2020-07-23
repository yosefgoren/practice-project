
namespace mtm
{
    class ParkingLot
    {
        ParkingLot() = delete;
        ~ParkingLot();
        
        /**
         * @param parkrkingBlockSizes - a total of 3 values (0,1,2):
         * [0] = Motorbike, [1] = HandicappedCar, [2] = Car
         */
        ParkingLot(unsigned int parkingBlockSizes[]);
        ParkingResult enterParking(VehicleType vehicleType, LicensePlate licensePlate, Time entranceTime);
    };
}