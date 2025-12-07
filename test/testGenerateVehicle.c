#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
/*int testGenerateSpecificVehicle(){
    char lp[8]="as74744";
    Vehicle v1 = {.isDisabled = true, .isElectric = false, .vehicleType = small};
    strcpy(v1.licensePlate, lp);
    Vehicle v2 =generateVehicle(lp,small,false,true);
    assert(v1.isDisabled==v2.isDisabled);
    assert(v1.isElectric==v2.isElectric);
    assert(v1.vehicleType==v2.vehicleType);
    printf("v1 %s",v1.licensePlate);
    printf("v2 %s",v2.licensePlate);
    assert(strcmp(v1.licensePlate,v2.licensePlate)==0);
}*/





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


void test_placeCar() {
    createParkingLot();


    Vehicle car = {"ABC1234", small, 0, 0};
    placeCar(spaces, car);


    ASSERT("Car ABC1234 should be in spot 0", strcmp(spaces[0].vehicle.licensePlate, "ABC1234") == 0);
    ASSERT("Spot 0 should be occupied", spaces[0].isOccupied == 1);
}


void test_findCar() {
    createParkingLot();


    Vehicle car = {"ZZZ9999", medium, 0, 0};
    placeCar(spaces, car);


    ParkingSpot* spot = findCar(spaces, "ZZZ9999");


    ASSERT("findCar should find ZZZ9999", spot != NULL);
    ASSERT("Returned spot should contain ZZZ9999", strcmp(spot->vehicle.licensePlate, "ZZZ9999") == 0);
}


void test_removeCar() {
    createParkingLot();


    Vehicle car = {"DEL1234", large, 0, 0};
    placeCar(spaces, car);


    ParkingSpot* spot = findCar(spaces, "DEL1234");


    Vehicle removed = removeCar(spot);


    ASSERT("removeCar should return DEL123", strcmp(removed.licensePlate, "DEL1234") == 0);
    ASSERT("Spot should be unoccupied after removal", spot->isOccupied == 0);
}




int main(){
    //testGenerateSpecificVehicle();
    printf("--- Running Parking System Tests ---\n");


    test_createParkingLot();
    //test_findCar();
    //test_removeCar();

}