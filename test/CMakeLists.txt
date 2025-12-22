cmake_minimum_required(VERSION 3.10)

enable_testing()

function(add_parking_test TEST_NAME TEST_SOURCE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME}
            PRIVATE
            parkingLot
            vehicle
            menu
            libconf
    )
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

add_parking_test(testCreateParkingLot testCreateParkingLot.c)
add_parking_test(test_PlaceCar test_PlaceCar.c)
add_parking_test(test_findFreeSpot test_findFreeSpot.c)
add_parking_test(test_removeCar test_removeCar.c)
add_parking_test(testGenerateVehicle testGenerateVehicle.c)
# target_link_libraries(testGenerateVehicle vehicle parkingLot menu)

# add_executable(test2 test.c)
 #target_link_libraries(test2 vehicle parkingLot menu)

# add_executable(simulation simulation.c)
# target_link_libraries(simulation vehicle parkingLot)
# --- Gen ---
 #add_test(NAME testGenerateVehicle
 #      COMMAND testGenerateVehicle)

# --- Test ---
# add_test(NAME test2
#         COMMAND test2)

# add_test(NAME simulation
#         COMMAND simulation)
