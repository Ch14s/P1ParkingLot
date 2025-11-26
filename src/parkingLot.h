#if !defined(PARKING_LOT)
#define PARKING_LOT
#include "vehicle.h"
#define PARKING_SPOTS 999

typedef struct {
    Vehicle vehicle;
    VehicleType vehicleType;
    int isElectric;
    int isDisable;

} ParkingSpot;

extern ParkingSpot spaces[PARKING_SPOTS];
void createParkingLot();
void placeCar(Vehicle car, ParkingSpot spaces[]);


#endif // PARKING_LOT
