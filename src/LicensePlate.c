#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include "LicensePlate.h"
static char **g_plates = NULL;
static size_t g_count = 0;
static size_t g_capacity = 0;
static bool g_initialized = false;

static void ensure_initialized(void) {
    if (!g_initialized) {
        initLicensePlates();
    }
}

void initLicensePlates(void) {
    // Start with a small initial capacity
    g_capacity = 8;
    g_count = 0;
    g_plates = (char**)calloc(g_capacity, sizeof(char*));
    g_initialized = (g_plates != NULL);
}

static char* dup_string(const char* s) {
    if (!s) return NULL;
    size_t len = strlen(s);
    char* copy = (char*)malloc(len + 1);
    if (!copy) return NULL;
    memcpy(copy, s, len + 1);
    return copy;
}

bool addLicensePlate(const char* plate) {
    ensure_initialized();
    if (!g_initialized) return false;

    // Grow array if needed
    if (g_count >= g_capacity) {
        size_t new_capacity = g_capacity ? g_capacity * 2 : 8;
        char **new_data = (char**)realloc(g_plates, new_capacity * sizeof(char*));
        if (!new_data) {
            return false;
        }
        // zero-initialize the new tail for cleanliness
        memset(new_data + g_capacity, 0, (new_capacity - g_capacity) * sizeof(char*));
        g_plates = new_data;
        g_capacity = new_capacity;
    }

    char* stored = dup_string(plate);
    if (!stored) return false;

    g_plates[g_count++] = stored;
    return true;
}

size_t getLicensePlateCount(void) {
    return g_count;
}

const char* getLicensePlateAt(size_t index) {
    if (index >= g_count) return NULL;
    return g_plates[index];
}

char* removeLicensePlateAt(size_t index) {
    if (!g_initialized) return NULL;
    if (index >= g_count) return NULL;


    char* removed = g_plates[index];


    for (size_t i = index + 1; i < g_count; ++i) {
        g_plates[i - 1] = g_plates[i];
    }


    g_plates[g_count - 1] = NULL;
    g_count--;

    return removed;
}

void clearLicensePlates(void) {
    if (!g_initialized) return;
    for (size_t i = 0; i < g_count; ++i) {
        free(g_plates[i]);
    }
    free(g_plates);
    g_plates = NULL;
    g_count = 0;
    g_capacity = 0;
    g_initialized = false;
}