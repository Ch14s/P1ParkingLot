#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

// Simple assert macro
#define ASSERT(msg, cond) \
if (!(cond)) { printf("[FAIL] %s\n", msg); } \
else { printf("[PASS] %s\n", msg); }


void test_createParkingLot() {
    createParkingLot();


    // Test first small spot
    ASSERT("Spot 0 should be unoccupied", spaces[0].isOccupied == 0);
    ASSERT("Spot 0 should be small", spaces[0].vehicleType == small);


    // Test EV zone
    ASSERT("Spot 950 should be EV", spaces[950].isElectric == 1);


    // Test disabled zone
    ASSERT("Spot 995 should be disabled", spaces[995].isDisable == 1);
}





int main(){
    printf("--- Running Parking System Tests ---\n");


    test_createParkingLot();
    int counter = emptySpacesSmall(spaces);
    printf("this is the counter: %d",counter);
}