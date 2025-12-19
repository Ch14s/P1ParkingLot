add_library(menu menu.c)
add_library(parkingLot parkingLot.c
        ../test/test_PlaceCar.c
        ../test/test_findFreeSpot.c
        ../test/test_removeCar.c)
add_library(vehicle vehicle.c)
add_library(libconf libconf.c)
configure_file(${CMAKE_SOURCE_DIR}/src/parkinglot.conf ${CMAKE_BINARY_DIR}/src/parkinglot.conf COPYONLY)

add_executable(main main.c
        LicensePlate.c
)
target_link_libraries(main menu parkingLot vehicle libconf)

