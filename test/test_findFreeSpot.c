#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>


// Ved ik hvordan jeg ændre fil navn. Det her tester findCar og ikke findFreeSPot

// Simple assert macro
#define ASSERT(msg, cond) \
if (!(cond)) { printf("[FAIL] %s\n", msg); } \
else { printf("[PASS] %s\n", msg); }




void test_findCar() {
    createParkingLot();


    Vehicle car = {"ZZZ9999", medium, 0, 0};
    placeCar(spaces, car);


    ParkingSpot* spot = findCar(spaces, "ZZZ9999");


    ASSERT("findCar should find ZZZ9999", spot != NULL);
    ASSERT("Returned spot should contain ZZZ9999", strcmp(spot->vehicle.licensePlate, "ZZZ9999") == 0);
}






int main(){

    printf("--- Running Parking System Tests ---\n");

    test_findCar();


}