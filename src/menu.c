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
            // registerCar();
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
    char handicappedinput;
    char electricinput;

    printf("\nPlease enter license plate > ");
    scanf("%s",licensePlate);
    printf("\nPlease enter vehicle size [s]/[m]/[l] > ");
    scanf(" %c",&size);
    printf("\nDo you have any accessibility needs [y]/[n] > ");
    scanf(" %c",&handicappedinput);
    printf("\nIs your vehicle electric [y]/[n] > ");
    scanf(" %c",&electricinput);

    //Confirmation, checks if the infor the user has typed is correct
    printf("\nplease confirm your input: ");
    printf("\n Licens plate: ""%s", licensePlate);
    printf("\n Vehicle size: ""%c", size);
    printf("\n Electric: ""%c", handicappedinput);
    printf("\n Handicapped: ""%c", electricinput);
    printf("\n");
    printf("is this information correct? [y]/[n]:  ");
    
    //convert chars to values
    VehicleType vehicleType = size=='s'?small:size=='m'?medium:large;
    int isHandicapped = (handicappedinput=='y'|| handicappedinput=='Y') ? 1 : 0;
    int isElectric = (electricinput=='y'|| electricinput=='Y') ? 1 : 0;



    printf("\n") ;
    char confirm;
    scanf(" %c",&confirm);
    if (confirm == 'y') {
        printf("\n perfect!\n");
        return generateVehicle(licensePlate,vehicleType,isElectric,isHandicapped);

    }
    else {
        printf("please try again");
        return registerCar();
    }
    

    
    

    
}

