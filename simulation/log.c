#include <stdio.h>
#include <stdlib.h>

#include "log.h"



int clog(const char *path, const char* message){
    FILE *f = fopen(path,"a");
    if (f==NULL)return EXIT_FAILURE;

    fprintf(f,"\n%s",message);

    fclose(f);
    
    return EXIT_SUCCESS;
}
