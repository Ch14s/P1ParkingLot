#if !defined(PARKING_LOT)
#define PARKING_LOT
#include "vehicle.h"
#define PARKING_SPOTS 999

typedef struct {
    Vehicle vehicle;
    VehicleType vehicleType;
    int isElectric;
    int isDisable;
    int isOccupied;
} ParkingSpot;

extern ParkingSpot spaces[PARKING_SPOTS];
void createParkingLot();
void placeCar(ParkingSpot *spaces, Vehicle car);
int findFreeSpot(ParkingSpot *spaces, Vehicle car);
Vehicle removeCar(ParkingSpot *spaces);
int emptySpacesSmall(ParkingSpot *spaces);
int emptySpacesMedium(ParkingSpot *spaces);
int emptySpacesLarge(ParkingSpot *spaces);
#endif // PARKING_LOT
