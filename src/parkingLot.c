#include "stdlib.h"
#include "stdio.h"
#include "parkingLot.h"

#include <stdbool.h>

#include "vehicle.h"
ParkingSpot createParkingLot(){

    ParkingSpot spaces[PARKING_SPOTS];
    for (int i = 0; i<300; i++) {
        spaces[i].vehicleType = small;
        spaces[i].isDisable = 0;
        spaces[i].isElectric = 0;
    }
    for (int i = 300; i<600; i++) {
        spaces[i].vehicleType = medium;
        spaces[i].isDisable = 0;
        spaces[i].isElectric = 0;
    }
    for (int i = 600; i<1000; i++) {
        spaces[i].vehicleType = large;
        spaces[i].isDisable = 0;
        if (i >939 && i < 989) {
            spaces[i].isElectric = 1;
        } else if (i >= 990) {
            spaces[i].isDisable = 1;
        }else{spaces[i].isElectric = 0;}
    }
    return spaces[999];
};

void placeCar(Vehicle car, int index ){
    spaces[index].vehicle;


}