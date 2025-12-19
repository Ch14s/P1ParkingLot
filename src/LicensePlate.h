#ifndef LICENSE_PLATE_H
#define LICENSE_PLATE_H

#include <stddef.h>
#include <stdbool.h>

void initLicensePlates(void);

bool addLicensePlate(const char* plate);

// Number of plates currently stored.
size_t getLicensePlateCount(void);

// Get a read-only pointer to a stored plate string at index, or NULL if out of range.
const char* getLicensePlateAt(size_t index);


char* removeLicensePlateAt(size_t index);


bool removeLicensePlate(const char* plate);


// Free all stored plates and reset internal storage.
void clearLicensePlates(void);

#endif // LICENSE_PLATE_H
