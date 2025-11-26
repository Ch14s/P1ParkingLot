#include "../src/vehicle.h"
#include <assert.h>
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
    printf("v1 %s",v1.licensePlate);
    printf("v2 %s",v2.licensePlate);
    assert(strcmp(v1.licensePlate,v2.licensePlate)==0);
}

int main(){
    testGenerateSpecificVehicle();
}