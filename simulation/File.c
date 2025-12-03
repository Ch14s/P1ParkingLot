#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "File.h"
char *read_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return NULL;

    // Go to end to find size
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    // Allocate buffer (+1 for null terminator)
    char *buffer = malloc(size + 1);
    if (!buffer)
    {
        fclose(f);
        return NULL;
    }

    fread(buffer, 1, size, f);
    buffer[size] = '\0'; // Null terminate

    fclose(f);
    return buffer;
}
char ** tokensFromFile(const char *path){
    long fileSize = sizeOfFile(path);
    char **tokv = malloc(fileSize);
    int tokc=0;
    // generate actions
    char *fptr = read_file(path);
    char *tok = strtok(fptr, " ");
    while (tok != NULL && tokc < fileSize - 1)
    {
        tokv[tokc++] = tok;
        tok = strtok(NULL, " ");
    }
    tokv[tokc] = NULL;
    return tokv;
}
long sizeOfFile(const char *path){
    FILE *f = fopen(path, "rb");
    if (!f)
        return NULL;

    // Go to end to find size
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);
    return size;
}
