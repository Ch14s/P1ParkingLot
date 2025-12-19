#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../src/libconf.h"
#include <stdlib.h>

#define CONFIG_PATH "../src/parkinglot.conf"

// Simple assert macro
#define ASSERT(msg, cond)           \
    if (!(cond))                    \
    {                               \
        printf("[FAIL] %s\n", msg); \
    }                               \
    else                            \
    {                               \
        printf("[PASS] %s\n", msg); \
    }

void test_removeCar()
{

    ParkingSpot *spaces = createParkingLot();
    initializeConfigFile(CONFIG_PATH);

    Vehicle car = {"DEL1234", large, 0, 0};
    placeCar(spaces, car);

    ParkingSpot *spot = findCar(spaces, "DEL1234");

    if (spot != NULL)
    {
        Vehicle removed = removeCar(spot);

        ASSERT("removeCar should return DEL1234", strcmp(removed.licensePlate, "DEL1234") == 0);
        ASSERT("Spot should be unoccupied after removal", spot->isOccupied == 0);
    }
    else
    {
        printf("[FAIL] Car not found\n");
    }
    freeConfig();
    free(spaces);
}

int main()
{

    printf("--- Running Parking System Tests ---\n");
    test_removeCar();
}