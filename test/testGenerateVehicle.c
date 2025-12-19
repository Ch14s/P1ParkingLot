#include "../src/vehicle.h"
#include "../src/parkingLot.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int testGenerateSpecificVehicle(){
    char lp[8]="as74744";
    Vehicle v1 = {.isDisabled = true, .isElectric = false, .vehicleType = small};
    strcpy(v1.licensePlate, lp);
    Vehicle v2 =generateVehicle(lp,small,false,true);
    assert(v1.isDisabled==v2.isDisabled);
    assert(v1.isElectric==v2.isElectric);
    assert(v1.vehicleType==v2.vehicleType);
    assert(strcmp(v1.licensePlate,v2.licensePlate)==0);
    printf("\nRANDOM VEHICLE SUCESSFULLY GENERATED");
    return EXIT_SUCCESS;
}
int testGenerateWithSpecificType(){
    Vehicle v = GenerateTypeVehicle(small);
    assert(v.vehicleType==small);
    printf("\nSMALL VEHICLE GENERATED");
    v = GenerateTypeVehicle(medium);
    assert(v.vehicleType==medium);
    printf("\nMEDIUM VEHICLE GENERATED");
    v = GenerateTypeVehicle(large);
    assert(v.vehicleType==large);
    printf("\nLARGE VEHICLE GENERATED");
    return EXIT_SUCCESS;
}








int main(){
    //testGenerateSpecificVehicle();

    testGenerateSpecificVehicle();
    testGenerateWithSpecificType();
}