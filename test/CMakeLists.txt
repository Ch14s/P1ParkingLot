add_executable(testGenerateVehicle testGenerateVehicle.c
        Test.c)
target_link_libraries(testGenerateVehicle vehicle parkingLot menu)

add_executable(test2 Test.c)
target_link_libraries(test2 vehicle parkingLot menu)

# --- Gen ---
add_test(NAME testGenerateVehicle
        COMMAND testGenerateVehicle)

# --- Test ---
add_test(NAME test2
        COMMAND test2)