#include <stdio.h>
#include <stdlib.h>

void warning(char * message){
    printf("\n[WARNING]: %s", message);
}

void fatal(char * message){
    printf("\n[FATAL]: %s", message);
    exit(1);
}
