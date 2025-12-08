#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#include "File.h"
#include "../src/parkingLot.h"
#include "../src/parkingLot.h"
// #include "../src/parkingLot.h"
#include "../src/vehicle.h"

#define NUMBER_OF_ACTIONS 10000

int *generateActions(int numberOfActions, int *actionArr);
int simulate(int numberOfActions, int *actionArr,char **lpv);
void setupSimulation();
int validateSimulation();
void parkAction();
void removeAction();

void setupSimulation()
{
    char path[] = "../src/licensePlates.txt";
    char **licensePlates = NULL;
    licensePlates = tokensFromFile(path);
    int *actionptr = calloc(NUMBER_OF_ACTIONS, sizeof(int));
    actionptr = generateActions(NUMBER_OF_ACTIONS, actionptr);
}
int *generateActions(int numberOfActions, int *actionArr)
{

    for (int i = 0; i < numberOfActions; i++)
    {
        if (i < 10)
        {
            actionArr[i] = 0;
        }
        else{
            
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
            parkAction(i,);
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

void parkAction(int i, char**lpv/*,Buffer*/)
{
    char* lp = lpv[i];
    //add lp to buf
    extern spaces;
    Vehicle v = GenerateLicensePlateVehicle(lp);
    placeCar(spaces, v);

}
void removeAction(int i)
{
}
void main()
{
    setupSimulation();
    // generateActions(NUMBER_OF_ACTIONS, actionptr, fptr);
}
