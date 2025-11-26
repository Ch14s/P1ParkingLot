#include "../src/vehicle.h"
#include "../src/menu.h"
#include "../src/parkingLot.h"
#include "../src/vehicle.h"
#include <assert.h>
#include <string.h>
#include <stdio.h> 

int main(){
    Vehicle v = generateRandomVehicle();

    printf("%s %d %d %d ", v.licensePlate, v.vehicleType, v.isDisabled ,v.isElectric);

    assert(1==1);
}