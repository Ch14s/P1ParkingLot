add_executable(testGenerateVehicle testGenerateVehicle.c)
target_link_libraries(testGenerateVehicle vehicle parkingLot menu)

# --- PARKINGLOT INTERACTIONS ---
add_test(NAME testGenerateVehicle
        COMMAND testGenerateVehicle)