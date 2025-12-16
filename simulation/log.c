#include <stdio.h>
#include <stdlib.h>

#include "log.h"

int customLog(const char *path, const char *prefix, const char *message)
{
    FILE *f = fopen(path, "a");
    if (f == NULL)
    {
        return EXIT_FAILURE;
    }

    fprintf(f, "\n%-10s%s", prefix, message);

    fclose(f);

    return EXIT_SUCCESS;
}
void clearLogFile(const char *path)
{
    FILE *f = fopen(path, "w");
    if (f == NULL)
    {
        return;
    }

    fclose(f);
}
int logData(const char *path, const char *data)
{
    FILE *f = fopen(path, "a");
    if (f == NULL)
    {
        return EXIT_FAILURE;
    }

    fprintf(f, "%s", data);

    fclose(f);

    return EXIT_SUCCESS;
}