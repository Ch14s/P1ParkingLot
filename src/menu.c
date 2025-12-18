#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

#include "parkingLot.h"
#include "vehicle.h"
#include "LicensePlate.h"
#define clear() printf("\e[1;1H\e[2J");

Vehicle registerCar();
Vehicle removeCarFromParking(ParkingSpot* spaces);
void findEmptyParkingSpace(const Vehicle vehicle, ParkingSpot* spaces);
void displayMenu(Vehicle *currentVehicle, bool *exitFlag, ParkingSpot* spaces)
{
    // Clear input buffer
    char choice = '\0';
    printf("Main menu: ");
    printf("\n[R]  -  Register car ");
    printf("\n[F]  -  Find Parking");
    printf("\n[E]  -  Leave Parking");
    printf("\n[Q]  -  Exit application");
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
        clear(); // clears screen

        break;
    case 'F':
    case 'f':
        clear(); // clears screen
        findEmptyParkingSpace(*currentVehicle,spaces);
        break;
    case 'E':
    case 'e':
        clear(); // clears screen
        *currentVehicle = removeCarFromParking(spaces);
        break;
    case 'Q':
    case 'q':
        *exitFlag = true;
        return;
        break;
    default:
        printf("Invalid input");
        break;
    }
    while ((getchar()) != '\n')
        ;
    return;
}
Vehicle registerCar()
{
    // request informatiion about the car
    char licensePlate[8];
    char size;
    char handicappedinput;
    char electricinput;

    printf("\nPlease enter license plate > ");
    scanf("%7s", licensePlate); // limit to 7 chars + null terminator to avoid overflow
    int RightInput = 0;
    do
    {

        printf("\nPlease enter vehicle size [s]/[m]/[l] > ");
        scanf(" %c", &size);
        if (size == 's' || size == 'm' || size == 'l' ||
            size == 'S' || size == 'M' || size == 'L')
        {
            RightInput = 1;
        }
        else
        {
            printf("please enter a valid input");
        }

    } while (RightInput == 0);

    printf("\nDo you have any accessibility needs [y]/[n] > ");
    scanf(" %c", &handicappedinput);
    printf("\nIs your vehicle electric [y]/[n] > ");
    scanf(" %c", &electricinput);

    // Confirmation, checks if the infor the user has typed is correct
    printf("\nplease confirm your input: ");
    printf("\n Licens plate: "
           "%s",
           licensePlate);
    printf("\n Vehicle size: "
           "%c",
           size);
    printf("\n Electric: "
           "%c",
           handicappedinput);
    printf("\n Handicapped: "
           "%c",
           electricinput);
    printf("\n");
    printf("is this information correct? [y]/[n]:  ");
    printf("Currently stored plates: %zu\n", getLicensePlateCount());
    for (size_t i = 0; i < getLicensePlateCount(); ++i)
    {
        printf("  %zu) %s\n", i + 1, getLicensePlateAt(i));
    }

    // convert chars to values
    VehicleType vehicleType = size == 's' ? small : size == 'm' ? medium
                                                                : large;
    int isHandicapped = (handicappedinput == 'y' || handicappedinput == 'Y') ? 1 : 0;
    int isElectric = (electricinput == 'y' || electricinput == 'Y') ? 1 : 0;

    printf("\n");
    char confirm;
    scanf(" %c", &confirm);
    if (confirm == 'y')
    {
        printf("\n perfect!\n");
        if (!addLicensePlate(licensePlate))
        {
            printf("Warning: could not store license plate in memory.\n");
        }
        return generateVehicle(licensePlate, vehicleType, isElectric, isHandicapped);
    }
    else
    {
        printf("please try again");
        return registerCar();
    }
}

void findEmptyParkingSpace(const Vehicle vehicle, ParkingSpot* spaces)
{
    char *location = placeCar(spaces, vehicle);
    if (strcmp(location, "1") == 0)
    {
        printf("\nNo available spots");
        return;
    }
    printf("Please park at %s", location);
    addLicensePlate(vehicle.licensePlate);
}
Vehicle removeCarFromParking(ParkingSpot* spaces)
{
    printf("\nPlease enter your license plate> ");
    char licensePlate[8];
    scanf("%s", licensePlate);
    ParkingSpot *parkingSpot = findCar(spaces, licensePlate);
    printf("Your car is located at %s", parkingSpot->location);
    removeCar(parkingSpot);
}