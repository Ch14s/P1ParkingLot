#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "parkingLot.h"
#include "vehicle.h"
int main(int argc, char** argv){
    Vehicle *currentVehicle;
    currentVehicle = (Vehicle*)calloc(1,sizeof(Vehicle));
    bool exitFlag = false;
    printf("Parking Management system! \n");
    createParkingLot(); // Her laver vi vores parkings plads så den er global til alle vores funktioner fuuuark
    Vehicle v = generateVehicle("dd44555",small,false,false);
    placeCar(spaces, v);
    ParkingSpot *spot = findCar(spaces,v.licensePlate);
    Vehicle rv = removeCar(spot);
    printf("this car is removed %s",rv.licensePlate);
    printf("spot i arrayet: %d \n", spaces[960].isElectric);
    /*do{
        displayMenu(currentVehicle,&exitFlag);
    }
    while(exitFlag); */


}

