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

    initializeConfigFile(PARKINGLOT_CONFIG_PATH);
    ParkingSpot* spaces = createParkingLot();
    printf("%s",getConfigValue("floor_count"));

    initLicensePlates();
    

    bool exitFlag = false;
    Vehicle currentVehicle = {0};

    while (!exitFlag) {
        displayMenu(&currentVehicle, &exitFlag, spaces);
        printf("\n\n");
    }
    freeConfig();
    free(spaces);

    clearLicensePlates();
    return 0;
}

