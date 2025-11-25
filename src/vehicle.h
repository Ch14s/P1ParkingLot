#if !defined(VEHICLE)
#define VEHICLE

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


#endif // VEHICLE
