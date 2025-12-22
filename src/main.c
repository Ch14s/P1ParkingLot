#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "parkingLot.h"
#include "vehicle.h"
#include "LicensePlate.h"
#include "libconf.h"

#define PARKINGLOT_CONFIG_PATH "parkinglot.conf"

int main(){
    // Initialize in-memory storage for license plates
    initializeConfigFile(PARKINGLOT_CONFIG_PATH);
    ParkingSpot* spaces = createParkingLot();
    printf("%s",getConfigValue("floor_count"));

    initLicensePlates();
    

    bool exitFlag = false;
    Vehicle currentVehicle = {0};
    // Simple loop to show the menu until the user quits
    while (!exitFlag) {
        displayMenu(&currentVehicle, &exitFlag, spaces);
        printf("\n\n");
    }
    freeConfig();
    free(spaces);
    // Cleanup allocated license plate memory before exiting
    clearLicensePlates();
    return 0;
}

