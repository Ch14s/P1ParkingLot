#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>

#include "File.h"
// #include "../src/parkingLot.h"
// #include "../src/vehicle.h"

#define NUMBER_OF_ACTIONS 10000

int *generateActions(int numberOfActions, int *actionArr);
int simulate(int numberOfActions, int *actionArr);
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
            actionArr[i] = 1;
        }
        else{
            
            actionArr[i] = rand() % 2; // 1 is park  2 is remove
        }
    }
    return actionArr;
}
int simulate(int numberOfActions, int *actionArr)
{
    srand(time(NULL));
    for (int i = 0; i < numberOfActions; i++)
    {
        switch (actionArr[i])
        {
        case 0:
            parkAction();
            break;
        case 1:
            removeAction();
            break;
        default:
            break;
        }
    }
}
int validateSimulation()
{
}

void parkAction()
{
}
void removeAction()
{
}
void main()
{
    setupSimulation();
    // generateActions(NUMBER_OF_ACTIONS, actionptr, fptr);
}
