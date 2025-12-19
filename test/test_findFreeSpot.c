#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/libconf.h"
#define CONFIG_PATH "../src/parkinglot.conf"

// Simple assert macro
#define ASSERT(msg, cond)           \
    if (!(cond))                    \
    {                               \
        printf("[FAIL] %s\n", msg); \
        return;                     \
    }                               \
    else                            \
    {                               \
        printf("[PASS] %s\n", msg); \
    }

void test_findCar()
{
    ParkingSpot *spaces = createParkingLot();
    initializeConfigFile(CONFIG_PATH);
    printf("init\n");
    Vehicle car = {"ZZZ9999", medium, 0, 0};
    placeCar(spaces, car);
    printf("car is placed\n");
    ParkingSpot *spot = findCar(spaces, "ZZZ9999");

    ASSERT("findCar should find ZZZ9999", spot != NULL);
    ASSERT("Returned spot should contain ZZZ9999", strcmp(spot->vehicle.licensePlate, "ZZZ9999") == 0);
    freeConfig();
    free(spaces);
}

int main()
{
    printf("--- Running Parking System Tests ---\n");
    test_findCar();
    printf("--- Tests Complete ---\n");
    return 0;
}