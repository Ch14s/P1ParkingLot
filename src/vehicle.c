#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vehicle.h"
#include <string.h>
#include <time.h>

//create struct Vehicle with all information given
Vehicle generateVehicle(char licensePLate[8],VehicleType vehicleType, bool isElectric, bool isHandicapped){
    Vehicle v = {.vehicleType = vehicleType, .isDisabled = isHandicapped, .isElectric = isElectric};
    strcpy(v.licensePlate,licensePLate);
    return v;
}


Vehicle generateRandomVehicle(){
    Vehicle v;

    srand(time(NULL));
    //Generate random licensePlate
    char licensePlate[8];
    for (int i = 0; i < 7; i++)
    {   
        licensePlate[i] = i<2?rand()%26+'A':rand()%9+'0';   // first 2 chars are letters rest are numbers (XX#####)
    }
    licensePlate[7]=0x00;
    strcpy(v.licensePlate,licensePlate);

    //generate random vehicle type
    v.vehicleType=rand()%3;

    //Generate random electric flag
    v.isElectric = rand()%2;

    //Generate random handicapped flag
    v.isDisabled = rand()%2;

    return v;
}
Vehicle GenerateTypeVehicle(VehicleType vehicleType){

}