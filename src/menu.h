#if !defined(MENU)
#define MENU
#include <stdbool.h>
#include "vehicle.h"
/**
 * @brief Displays the TUI
 * 
 * @param currentVehicle The vehicle currently being modified
 * @param exitFlag bool If true the program will exit
 */
void displayMenu(Vehicle* currentVehicle, bool exitFlag);

#endif // MENU
