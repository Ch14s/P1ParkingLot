#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libconf.h"

#define CONF_DELIMITER "\r\n"

typedef struct
{
    char **tokv;
    int tokc;
} TokenKeyValuePairs;

static _config_c config_c;
static char *buffer;
static bool _isInitialized = false;

void read_file(const char *path, size_t configSize);
size_t getFileSize(const char *path);
void clearConfigBuffer();
TokenKeyValuePairs tokenerizeKeyValuePairs(const char *path, size_t configSize);

void read_file(const char *path, size_t configSize)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return;

    buffer = malloc(configSize + 1); // Allocate buffer (+1 for null terminator)
    if (!buffer)
    {
        fclose(f);
        return;
    }

    fread(buffer, 1, configSize, f);
    buffer[configSize] = '\0'; // Null terminate

    fclose(f);
    return;
}
size_t getFileSize(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return 0;

    // Go to end to find size
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fclose(f);
    return size;
}
void clearConfigBuffer()
{
    if (!buffer)
        return;
    free(buffer);
    buffer = NULL;
}
TokenKeyValuePairs tokenerizeKeyValuePairs(const char *path, size_t configSize)
{
    size_t tokc = 0;
    char **tokv = (char **)malloc(sizeof(char *) * 16);
    size_t cap = 16;
    char *tok = strtok(buffer, CONF_DELIMITER);
    while (tok != NULL && tokc < configSize)
    {
        if (tok[0] != '#')
            tokv[tokc++] = tok;

        tok = strtok(NULL, CONF_DELIMITER);

        if (tokc == cap)
        {
            cap *= 2;
            tokv = realloc(tokv, cap * sizeof(char *));
        }
    }
    tokv[tokc] = NULL; // Terminate string

    TokenKeyValuePairs returnStruct = {.tokv = tokv, .tokc = tokc};
    return returnStruct;
}

void initializeConfigFile(const char *path)
{
    size_t configSize = getFileSize(path);
    if (_isInitialized)
        return;
    read_file(path,configSize);
    if (!buffer)
        return; // check the buffer has been created
    TokenKeyValuePairs tokenKeyValuePairs = tokenerizeKeyValuePairs(path, configSize);

    config_c._config_a = (_config_i *)calloc(tokenKeyValuePairs.tokc, sizeof(_config_i));
    if (!config_c._config_a)
        return;

    for (size_t i = 0; i < tokenKeyValuePairs.tokc; i++)
    {
        char *k = strtok(tokenKeyValuePairs.tokv[i], "=");
        char *v = strtok(NULL, "=");

        if (!k || !v)
            continue;

        strncpy(config_c._config_a[i].key, k, sizeof(config_c._config_a[i].key) - 1);
        strncpy(config_c._config_a[i].value, v, sizeof(config_c._config_a[i].value) - 1);
    }
    config_c.count = tokenKeyValuePairs.tokc;

    free(tokenKeyValuePairs.tokv);
    clearConfigBuffer();
    _isInitialized = true;
    return;
}
void freeConfig()
{
    if (!_isInitialized)
        return;
    free(config_c._config_a);
    config_c._config_a = NULL;
    config_c.count = 0;
    _isInitialized = false;
}
char *getConfigValue(const char *key)
{
    for (size_t i = 0; i < config_c.count; i++)
    {
        if (strcmp(config_c._config_a[i].key, key) != 0)
            continue;
        return config_c._config_a[i].value;
    }
    return NULL;
}