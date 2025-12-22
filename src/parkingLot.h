#if !defined(PARKING_LOT)
#define PARKING_LOT
#include "vehicle.h"
typedef struct {
    Vehicle vehicle;
    VehicleType vehicleType;
    int isElectric;
    int isDisable;
    int isOccupied;
    char location[30];
} ParkingSpot;

/**
 * @brief Create a Parking Lot object Note config must be initialized first
 * 
 * @return ParkingSpot* returns an array of parkinglots
 */
ParkingSpot* createParkingLot();

/**
 * @brief Places a vehicle into the parkinglot array
 * 
 * @param spaces The parking lot arrray
 * @param car   vehicle to be placed
 * @return char* returns location string of where to park car
 */
char* placeCar(ParkingSpot *spaces, Vehicle car);

/**
 * @brief Finds a free spot for a car
 * 
 * @param spaces array of parking spaces
 * @param car   vehicle to be placed
 * @return int returns index where spaces is
 */
int findFreeSpot(ParkingSpot *spaces, Vehicle car);

/**
 * @brief Locate a given vehicle by licenseplate within parkinglot
 * 
 * @param spaces array of parking spaces
 * @param licensePlate licenseplate to locate
 * @return ParkingSpot* returns the spot where the car is located 
 */
ParkingSpot* findCar(ParkingSpot* spaces, char licensePlate[8]);

/**
 * @brief Removes a car from a given parkingspace
 * 
 * @param spaces the space to remove car from
 * @return Vehicle returns the vehicle in a given space
 */
Vehicle removeCar(ParkingSpot *spaces);

/**
 * @brief Amount of empty small spaces
 * 
 * @param spaces array of parkingspaces
 * @return int count of small spaces
 */
int emptySpacesSmall(ParkingSpot *spaces);

/**
 * @brief Amount of empty medium spaces
 * 
 * @param spaces array of parkingspaces
 * @return int count of medium spaces
 */
int emptySpacesMedium(ParkingSpot *spaces);

/**
 * @brief Amount of empty large spaces
 * 
 * @param spaces array of parkingspaces
 * @return int count of large spaces
 */
int emptySpacesLarge(ParkingSpot *spaces);

/**
 * @brief Randomizes index of parkinglot
 * 
 * @param spaces array of parking spots.
 */
void shuffleParkingLot(ParkingSpot *spaces);
#endif // PARKING_LOT
