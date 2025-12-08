#ifndef LICENSE_PLATE_H
#define LICENSE_PLATE_H

#include <stddef.h>
#include <stdbool.h>

// Initialize the in-memory license plate list. Safe to call multiple times.
void initLicensePlates(void);

// Add a license plate to the list by copying it with malloc.
// Returns true on success, false on allocation failure.
bool addLicensePlate(const char* plate);

// Number of plates currently stored.
size_t getLicensePlateCount(void);

// Get a read-only pointer to a stored plate string at index, or NULL if out of range.
const char* getLicensePlateAt(size_t index);


char* removeLicensePlateAt(size_t index);

// Free all stored plates and reset internal storage.
void clearLicensePlates(void);

#endif // LICENSE_PLATE_H
