#if !defined(PARKING_LOT)
#define PARKING_LOT
#include "vehicle.h"
#define PARKING_SPOTS 999

typedef struct {
    Vehicle vehicle;
    VehicleType vehicleType;
    int isElectric;
    int isDisable;

} parkingSpot;

parkingSpot spaces[PARKING_SPOTS];



#endif // PARKING_LOT
