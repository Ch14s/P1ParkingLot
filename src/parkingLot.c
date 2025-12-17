#include "parkingLot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
ParkingSpot spaces[PARKING_SPOTS];

void createParkingLot()
{

    for (int i = 0; i < PARKING_SPOTS; i++)
    {
        spaces[i].isOccupied = 0; // alle pladser er tomme i starten
    }

    // Small plads
    for (int i = 0; i < 300; i++)
    {
        spaces[i].vehicleType = small;
        spaces[i].isElectric = 0;
        spaces[i].isDisable = 0;
    }

    // Medium plads
    for (int i = 300; i < 600; i++)
    {
        spaces[i].vehicleType = medium;
        spaces[i].isElectric = 0;
        spaces[i].isDisable = 0;
    }

    // Large, EV, Disabled pladser
    for (int i = 600; i < PARKING_SPOTS; i++)
    {
        spaces[i].vehicleType = large;

        if (i >= 940 && i < 989)
        {
            spaces[i].isElectric = 1; // laver et elektrisk plads
            spaces[i].isDisable = 0;
        }
        else if (i >= 989)
        {
            spaces[i].isDisable = 1; // laver et handicap plads
            spaces[i].isElectric = 0;
        }
        else
        {
            spaces[i].isElectric = 0;
            spaces[i].isDisable = 0;
        }
    }

    printf("Parking lot created successfully.\n");
    srand((unsigned int)time(NULL)); // Srand gør så det er totalt random numre, hvor p-pladserne bliver sat
    shuffleParkingLot(spaces);
}

int findFreeSpot(ParkingSpot *spaces, Vehicle car)
{

    // Første skridt: Handicap biler finder en handicap plads
    if (car.isDisabled)
    {
        for (int i = 0; i < PARKING_SPOTS; i++)
        {
            if (spaces[i].isDisable == 1 &&
                spaces[i].isOccupied == 0 &&
                car.vehicleType <= spaces[i].vehicleType)
            {
                return i; // returnere en plads til handicap biler, hvis en er tilgængelig
            }
        }
    }

    // Andet skridt: EV biler finder en EV plads
    if (car.isElectric)
    {
        for (int i = 0; i < PARKING_SPOTS; i++)
        {
            if (spaces[i].isElectric == 1 &&
                spaces[i].isOccupied == 0 &&
                car.vehicleType <= spaces[i].vehicleType)
            {
                return i; // Så vælger EV biler EV pladser
            }
        }
    }
    int freeSmallSpaces = emptySpacesSmall(spaces);
    int freeMediumSpaces = emptySpacesMedium(spaces);
    int freeLargeSpaces = emptySpacesLarge(spaces);
    // tredje skridt: hvad end plads der er ledig
    for (int i = 0; i < PARKING_SPOTS; i++)
    {

        // pladsen skal være tom
        if (spaces[i].isOccupied != 0)
            continue;

        // disabled regl: Kun handicap biler kan holde på handicap pladser
        if (!car.isDisabled && spaces[i].isDisable == 1)
            continue;

        /* EV regl: kun EV biler på EV pladser. Vi ku kigge ind i at lade andre
         biler holde der, hvis ingen pladser er tilgængelige */
        if (!car.isElectric && spaces[i].isElectric == 1)
            continue;
        // størrelses check
        switch (car.vehicleType)
        {
        case small:
            if (freeSmallSpaces == 0)
            {
                if (freeMediumSpaces == 0)
                {
                    if (freeLargeSpaces == 0)
                        return-1;
                    if (spaces[i].vehicleType == large)
                        return i;
                }
                if (spaces[i].vehicleType == medium)
                    return i;
            }
            if (spaces[i].vehicleType == small)
                return i;
            break;
        case medium:
            if (freeMediumSpaces == 0)
            {
                if (freeLargeSpaces == 0)
                    return-1;
                if (spaces[i].vehicleType == large)
                    return i;
            }
            if (spaces[i].vehicleType == medium)
                return i;
            break;
        case large:
            if(freeLargeSpaces==0)return-1;
            if (spaces[i].vehicleType == large)
                return i;
            break;
        }
    }

    return -1; // ingen plads tilgængelig.
}

int placeCar(ParkingSpot *spaces, Vehicle car)
{

    int index = findFreeSpot(spaces, car);

    if (index == -1)
    {
        printf("No suitable parking spot found.\n");
        return EXIT_FAILURE;
    }

    // sætter bilen ind i pladsen
    spaces[index].vehicle = car;
    spaces[index].isOccupied = 1;

    // printf("Car parked at spot %d.\n", index);
    return EXIT_SUCCESS;
}

ParkingSpot *findCar(ParkingSpot *spaces, char licensePlate[8])
{
    for (int i = 0; i < PARKING_SPOTS; i++)
    {
        if (strcmp(spaces[i].vehicle.licensePlate, licensePlate) == 0) /*tjekker om nummer pladen er
            på en af pladserne */
        {
            return &spaces[i];
        }
    }
    return NULL;
}

Vehicle removeCar(ParkingSpot *spaces)
{

    spaces[0].isOccupied = 0;
    return spaces[0].vehicle;
}

int emptySpacesSmall(ParkingSpot *spaces)
{

    int counter = 0;

    for (int i = 0; i < PARKING_SPOTS; i++)
    {
        if (spaces[i].vehicleType == small && spaces[i].isOccupied == false)
        {
            counter += 1;
        }
    }
    return counter;
}

int emptySpacesMedium(ParkingSpot *spaces)
{
    int counter = 0;

    for (int i = 0; i < PARKING_SPOTS; i++)
    {
        if (spaces[i].vehicleType == medium && spaces[i].isOccupied == false)
        {
            counter += 1;
        }
    }
    return counter;
}

int emptySpacesLarge(ParkingSpot *spaces)
{
    int counter = 0;

    for (int i = 0; i < PARKING_SPOTS; i++)
    {
        if (spaces[i].vehicleType == large && spaces[i].isOccupied == false)
        {
            counter += 1;
        }
    }
    return counter;
}

void shuffleParkingLot(ParkingSpot *spaces)
{
    for (int i = PARKING_SPOTS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        ParkingSpot temp = spaces[i];
        spaces[i] = spaces[j];
        spaces[j] = temp;
    }
}
