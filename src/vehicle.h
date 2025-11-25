#if !defined(VEHICLE)
#define VEHICLE
#include <stdbool.h>

typedef enum {
    small,
    medium,
    large
}VechileType;

/**
 * @brief Structure of a car 
 * 
 */
typedef struct
{
    char licensePlate[8];
    VechileType vehicleType;
    int isElectric;
    int isDisabled;
}Vehicle;


Vehicle generateVehicle(char licensePLate[8],VechileType vehicleType, bool isElectric, bool isHandicapped);

#endif // VEHICLE
