#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "parkingLot.h"
#include "parkingLot.c"
int main(int argc, char** argv){
    Vehicle *currentVehicle;
    bool exitFlag = false;
    printf("Parking Management system! \n");
    createParkingLot(); // Her laver vi vores parkings plads så den er global til alle vores funktioner fuuuark

    do{
        displayMenu(currentVehicle,&exitFlag);
    }
    while(exitFlag);


}

