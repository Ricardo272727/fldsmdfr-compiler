#include "../file.h"

int main(){

    FILE * fp = fopen("example_file.c", "r");
    // test get size
    long int size = get_size_file(fp);
    printf("\nsize file: %ld\n", size);
    fclose(fp);

    // test open file
    struct File * file = open_file("example_file.c");
    int i;
    print_file(file);
   

    return 0;
}