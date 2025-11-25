#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vehicle.h"
#include <string.h>

Vehicle generateVehicle(char licensePLate[8],VehicleType vehicleType, bool isElectric, bool isHandicapped){
    //create struct Vehicle
    Vehicle v = {.vehicleType = vehicleType, .isDisabled = isHandicapped, .isElectric = isElectric};
    strcpy(v.licensePlate,licensePLate);
    return v;
}