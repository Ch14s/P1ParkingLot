#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../src/libconf.h"
#include <stdlib.h>
#define CONFIG_PATH "../src/parkinglot.conf"

// Simple assert macro
#define ASSERT(msg, cond) \
if (!(cond)) { printf("[FAIL] %s\n", msg); } \
else { printf("[PASS] %s\n", msg); }


void test_createParkingLot(ParkingSpot *spaces) {
    

    // Test first small spot
    ASSERT("Spot 0 should be unoccupied", spaces[0].isOccupied == 0);
}





int main(){
    printf("--- Running Parking System Tests ---\n");
ParkingSpot *spaces = createParkingLot();
    initializeConfigFile(CONFIG_PATH);
    test_createParkingLot(spaces);
    int counter = emptySpacesSmall(spaces);
    printf("this is the counter: %d",counter);
    freeConfig();
    free(spaces);
}