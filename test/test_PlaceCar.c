#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include "../src/libconf.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// DISCLAIMER. VI TESTER BÅDE findFreeSpot og placeCar.

// Simple assert macro
#define ASSERT(msg, cond) \
if (!(cond)) { printf("[FAIL] %s\n", msg); } \
else { printf("[PASS] %s\n", msg); }

#define CONFIG_PATH "../src/parkinglot.conf"



void test_placeCar() {
    
    ParkingSpot *spaces = createParkingLot();
    initializeConfigFile(CONFIG_PATH);
    Vehicle car = {"ABC1234", small, 0, 0};
    placeCar(spaces, car);


    ASSERT("Car ABC1234 should be in spot 0", strcmp(spaces[0].vehicle.licensePlate, "ABC1234") == 0);
    ASSERT("Spot 0 should be occupied", spaces[0].isOccupied == 1);

    freeConfig();
    free(spaces);
}








int main(){

    printf("--- Running Parking System Tests ---\n");

    test_placeCar();


}

