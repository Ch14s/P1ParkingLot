#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "vehicle.h"

Vehicle registerCar();

void displayMenu(Vehicle* currentVehicle, bool *exitFlag)
{
    char choice = '\0';
    printf("Main menu: ");
    printf("\n(R)  -  Register car ");
    printf("\n(F)  -  Find Parking" );
    printf("\n(E)  -  Leave Parking");
    if (scanf("%c", &choice) == 0)
    {
        printf("Error reading input");
        return;
    }
    switch (choice)
    {
    case 'R':
    case 'r':
        *currentVehicle = registerCar();
        break;
    case 'F':
    case 'f':
        
        // FindEmptyParkingSpace();
        break;
    case 'Q':
    case 'q':
        *exitFlag=true;
        return;
    break;
    default:
        printf("Invalid input");
        break;
    }
    return;
}
Vehicle registerCar()
{
    //request informatiion about the car
    char licensePlate[8];
    char size;
    int isElectric;
    int isHandicapped;
    printf("\nPlease enter license plate > ");
    scanf("%s",licensePlate);
    printf("\nPlease enter vehicle size [s]/[m]/[l] > ");
    scanf("%c",&size);
    printf("\nDo you have any accessibility needs [y]/[n] > ");
    scanf("%d",&isHandicapped);
    printf("\nIs your vehicle electric [y]/[n] > ");
    scanf("%d",&isElectric);

    VehicleType vehicleType = size=='s'?small:size=='m'?medium:large;
    return generateVehicle(licensePlate,size,isElectric,isHandicapped);
    
}

