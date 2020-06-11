#include <stdio.h>

#define FLDSMDFR 27


int main(){

    char * mensaje = "Hola mundo!"; 
    int i;
    printf("%s", mensaje);

    for(i = 0; i < 100; i++)
        printf("%d, ", &i);

    return 0;
}
