#if !defined(VEHICLE)
#define VEHICLE
#include <stdbool.h>

typedef enum {
    small,
    medium,
    large
}VehicleType;

/**
 * @brief Structure of a car 
 * 
 */
typedef struct
{
    char licensePlate[8];
    VehicleType vehicleType;
    int isElectric;
    int isDisabled;
}Vehicle;

/**
 * @brief Generates Vehicle 
 * 
 * @param licensePLate  char[8] Lisence plate of Vehicle
 * @param vehicleType  enum VehicleType Type of vehcile 
 * @param isElectric  Bool whether the vechile is electric 
 * @param isHandicapped  Boolwhether the vechile is handicapped
 * @return Vehicle 
 */
Vehicle generateVehicle(char licensePLate[8],VehicleType vehicleType, bool isElectric, bool isHandicapped);

/**
 * @brief Function to generate a random vehicle
 * 
 * @return Random vehicle 
 */
Vehicle generateRandomVehicle();

/**
 * @brief Function for generating a vehicle with specific type
 * 
 * @param vehicleType the type of the vehicle (small/mmedium/large) 
 * @return random vehicle with specifc type
 */
Vehicle GenerateTypeVehicle(VehicleType vehicleType);

/**
 * @brief Print information of vehicle to stdout
 * 
 * @param vehicle 
 */
void printVehicleInformation(Vehicle vehicle);

/**
 * @brief Get a pointer for a vehicle
 * 
 * @param vehicle 
 * @return Vehicle* 
 */
Vehicle* allocateMemoryForVehicle(Vehicle vehicle);

/**
 * @brief Free a vehicle from memory
 * 
 */
void deAllocateMemoryForVehicle(Vehicle* vehicle);
#endif // VEHICLE
