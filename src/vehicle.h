#if !defined(VEHICLE)
#define VEHICLE

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
}vehicle;


#endif // VEHICLE
