#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>

#include "File.h"
#include "../src/parkingLot.h"
#include "../src/parkingLot.h"
#include "log.h"
#include "../src/LicensePlate.h"
#include "../src/libconf.h"
// #include "../src/parkingLot.h"
#include "../src/vehicle.h"

#define NUMBER_OF_ACTIONS 10000
#define LOG_PATH "res/SIM_LOG.txt"
#define CSV_PATH "res/SIM_RES.csv"

/**
 * @brief The leave multiplier is added in order to increase the odds of a leave action being generated. This is neccessary because park action take priority in generation of actions
 *
 */
#define LEAVE_MULTIPLIER 2
#define INIT_PARK_ACTIONS_RANDOM_DEMAND 970

int *generateActionsRandomDemand(int numberOfActions, int *actionArr);
int *generateActionsTimeDemand(int numberOfActions, int *actionArr);
int simulate(int numberOfActions, int *actionArr, char **lpv, ParkingSpot* spaces);
void setupSimulation();
int validateSimulation();
void parkAction(int i, char **lpv, ParkingSpot* spaces);
void removeAction(int i, ParkingSpot* spaces);
void logPark(int i, int action, VehicleType vehicleType, int isElectric, int isDisabled, int isSuccess, int hour, ParkingSpot* spaces);
void setupSimulation()
{
}
int *generateActionsRandomDemand(int numberOfActions, int *actionArr)
{
    int sum = 0;
    for (int i = 0; i < numberOfActions; i++)
    {
        if (i < INIT_PARK_ACTIONS_RANDOM_DEMAND || !(i / 2 > sum))
        {
            actionArr[i] = 0;
        }
        else
        {

            actionArr[i] = rand() % 2; // 1 is park  2 is remove
            sum += actionArr[i];
        }
    }
    return actionArr;
}
int *generateActionsTimeDemand(int numberOfActions, int *actionArr)
{
    int demandArray[17] = {60, 250, 700, 875, 675, 450, 425, 500, 575, 625, 725, 775, 760, 675, 550, 425, 250};
    int sum = 0;
    int beginingHour = 6;
    int endingHour = 23;
    for (int hour = beginingHour; hour < endingHour; hour++)
    {
        for (int i = 0; i < numberOfActions / (endingHour - beginingHour); i++)
        {
            if (rand() % 1000 < demandArray[hour - beginingHour])
            {
                actionArr[i + (numberOfActions / (endingHour - beginingHour)) * (hour - beginingHour) - 1] = 0;
            }
            else if (rand() % 1000 < demandArray[hour - beginingHour - 1] * LEAVE_MULTIPLIER && hour != beginingHour)
            {
                actionArr[i + (numberOfActions / (endingHour - beginingHour)) * (hour - beginingHour) - 1] = 1;
            }
            else
            {
                actionArr[i + (numberOfActions / (endingHour - beginingHour)) * (hour - beginingHour) - 1] = 2;
            }
        }
    }

    return actionArr;
}

int simulate(int numberOfActions, int *actionArr, char **lpv, ParkingSpot* spaces)
{
    for (int i = 0; i < numberOfActions; i++)
    {
        switch (actionArr[i])
        {
        case 0:
            parkAction(i, lpv, spaces);
            break;
        case 1:
            removeAction(i, spaces);
            break;
        default:
            logPark(i, 2, -1, -1, -1, 1, i / (NUMBER_OF_ACTIONS / 17),spaces);

            break;
        }
        printf("\n%d", i);
    }
}
int validateSimulation()
{
}

void parkAction(int i, char **lpv, ParkingSpot* spaces)
{
    char *lp = lpv[i];
    // add lp to buf
    // spaces[];
    Vehicle v = GenerateLicensePlateVehicle(lp);
    char* location = placeCar(spaces, v);
    if(strcmp(location,"1") ==0)
    {
        char failStr[100] = "Failed to park car:";
        // printVehicleInformation(v);
        customLog(LOG_PATH, "[!]", failStr);
        logPark(i, 0, v.vehicleType, v.isElectric, v.isDisabled, 0, i / (NUMBER_OF_ACTIONS / 17),spaces);
        return;
    }
    addLicensePlate(lp);
    char str1[100] = "Car parked with license plate: ";
    customLog(LOG_PATH, "[=>]", strcat(str1, v.licensePlate));
    logPark(i, 0, v.vehicleType, v.isElectric, v.isDisabled, 1, i / (NUMBER_OF_ACTIONS / 17),spaces);
}
void removeAction(int i , ParkingSpot* spaces)
{
    if (getLicensePlateCount() == 0)
    {
        logPark(i, 1, -1, -1, -1, 0, i / (NUMBER_OF_ACTIONS / 17),spaces);
        char str1[100] = "No license plates in the buffer";
        customLog(LOG_PATH, "[NO CARS]", str1);
        return;
    }
    int licensePlatelateToRemove = rand() % getLicensePlateCount();
    char lp[8];
    strcpy(lp, removeLicensePlateAt(licensePlatelateToRemove));
    ParkingSpot *ps = findCar(spaces, lp);
    if (ps == NULL)
    {

        logPark(i, 1, -1, -1, -1, 0, i / (NUMBER_OF_ACTIONS / 17),spaces);
        char str1[100] = "Couldnt find car with given plate ";
        customLog(LOG_PATH, "[N_FOUND]", str1);
        return;
    }
    char str1[100] = "Remove license plate: ";
    customLog(LOG_PATH, "[<=]", strcat(str1, ps->vehicle.licensePlate));
    logPark(i, 1, ps->vehicle.vehicleType, ps->vehicle.isElectric, ps->vehicle.isDisabled, 1, i / (NUMBER_OF_ACTIONS / 17),spaces);
    removeCar(ps);
}
void main()
{
    initializeConfigFile("../src/parkinglot.conf");
    initLicensePlates();
    srand(time(NULL));
    clearLogFile(LOG_PATH);
    clearLogFile(CSV_PATH);
    ParkingSpot* spaces = createParkingLot();
    printf("%d",emptySpacesSmall(spaces));

    char path[] = "../src/licensePlates.txt";
    char **licensePlates = NULL;
    int *actionptr = calloc(NUMBER_OF_ACTIONS, sizeof(int));

    actionptr = generateActionsTimeDemand(NUMBER_OF_ACTIONS, actionptr);
    licensePlates = tokensFromFile(path);
    logData(CSV_PATH, "index;action;size;isElectric;isDisabled;isSuccess;hour;smallFreeSpaces;mediumFreeSpaces;largeFreeSpaces\n");
    simulate(NUMBER_OF_ACTIONS, actionptr, licensePlates, spaces);

    free(licensePlates);
    free(spaces);
    // generateActions(NUMBER_OF_ACTIONS, actionptr, fptr);
}

void logPark(int index, int action, VehicleType vehicleType, int isElectric, int isDisabled, int isSuccess, int hour, ParkingSpot* spaces)
{

    char strbuffer[200];
    sprintf(strbuffer, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d\n", index, action, vehicleType, isElectric, isDisabled, isSuccess, hour, emptySpacesSmall(spaces), emptySpacesMedium(spaces), emptySpacesLarge(spaces));
    logData(CSV_PATH, strbuffer);
}