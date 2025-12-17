#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "parkingLot.h"
#include "vehicle.h"
#include "LicensePlate.h"

int main(int argc, char** argv){
    // Initialize in-memory storage for license plates
    initLicensePlates();
    createParkingLot();

    bool exitFlag = false;
    Vehicle currentVehicle = {0};
    // Simple loop to show the menu until the user quits
    while (!exitFlag) {
        displayMenu(&currentVehicle, &exitFlag);
        printf("\n\n");
    }

    // Cleanup allocated license plate memory before exiting
    clearLicensePlates();
    return 0;
}

