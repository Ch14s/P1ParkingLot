#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#include "File.h"
#include "../src/parkingLot.h"
#include "../src/parkingLot.h"
#include "log.h"
#include "../src/LicensePlate.h"
// #include "../src/parkingLot.h"
#include "../src/vehicle.h"

#define NUMBER_OF_ACTIONS 20
#define LOG_PATH "SIM_LOG.txt"

int *generateActions(int numberOfActions, int *actionArr);
int simulate(int numberOfActions, int *actionArr, char **lpv);
void setupSimulation();
int validateSimulation();
void parkAction();
void removeAction();

void setupSimulation()
{


}
int *generateActions(int numberOfActions, int *actionArr)
{

    for (int i = 0; i < numberOfActions; i++)
    {
        if (i < 10)
        {
            actionArr[i] = 0;
        }
        else
        {

            actionArr[i] = rand() % 2; // 1 is park  2 is remove
        }
    }
    return actionArr;
}
int simulate(int numberOfActions, int *actionArr, char **lpv)
{
    srand(time(NULL));
    for (int i = 0; i < numberOfActions; i++)
    {
        switch (actionArr[i])
        {
        case 0:
            parkAction(i, lpv);
            break;
        case 1:
            removeAction(i);
            break;
        default:
            break;
        }
    }
}
int validateSimulation()
{
}

void parkAction(int i, char **lpv /*,Buffer*/)
{
    char *lp = lpv[i];
    addLicensePlate(lp);
    // add lp to buf
    // spaces[];
    Vehicle v = GenerateLicensePlateVehicle(lp);
    placeCar(spaces, v);
    char str1[100] = "Car parked with license plate: ";
    customLog(LOG_PATH,"[=>]", strcat(str1,v.licensePlate));
}
void removeAction(int in /*,Buffer*/)
{
    // srand(time(NULL));
    // int licensePlatelateToRemove = rand() % getLicensePlateCount();
    // char* str1 = "Remove license plate: ";
    // customLog(LOG_PATH,"[<=]", strcat(str1,licensePlatelateToRemove));
}
void main()
{
    initLicensePlates();

    clearLogFile(LOG_PATH);
    createParkingLot();
    char path[] = "../src/licensePlates.txt";
    char **licensePlates = NULL;
    int *actionptr = calloc(NUMBER_OF_ACTIONS, sizeof(int));
    actionptr = generateActions(NUMBER_OF_ACTIONS, actionptr);
    licensePlates = tokensFromFile(path);
    

    simulate(NUMBER_OF_ACTIONS, actionptr, licensePlates);
    // generateActions(NUMBER_OF_ACTIONS, actionptr, fptr);
}
