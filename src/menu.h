#if !defined(MENU)
#define MENU
#include <stdbool.h>
#include "vehicle.h"
#include "parkingLot.h"
/**
 * @brief Displays the TUI
 * 
 * @param currentVehicle The vehicle currently being modified
 * @param exitFlag bool If true the program will exit
 * @param spaces poitner to Parkingspot array
 *  */
void displayMenu(Vehicle* currentVehicle, bool *exitFlag, ParkingSpot* spaces);

#endif // MENU
