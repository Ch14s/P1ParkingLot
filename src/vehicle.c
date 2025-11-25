#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vehicle.h"

Vehicle generateVehicle(char licensePLate[8],VehicleType vehicleType, bool isElectric, bool isHandicapped){
    //create struct Vehicle
    Vehicle v = {.licensePlate = licensePLate, .vehicleType = vehicleType, .isDisabled = isHandicapped, .isElectric = isElectric};
    return v;
}