add_library(menu menu.c)
add_library(parkingLot parkingLot.c)
add_library(vehicle vehicle.c)

add_executable(main main.c)
target_link_libraries(main menu parkingLot vehicle)

