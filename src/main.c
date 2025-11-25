#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "vehicle.h"
int main(int argc, char** argv){
    Vehicle * currentVehicle;
    bool exitFlag = false;
    printf("Parking Management system! \n");
    do
    {
        displayMenu(currentVehicle,exitFlag);
    } while (exitFlag);
    

    free(currentVehicle);
}

