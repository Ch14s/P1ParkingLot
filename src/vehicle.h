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

#endif // VEHICLE
