#include <stdio.h>
#include <stdlib.h>
#include "alert.h"

#define MAX_SIZE_FILE 2048

struct File {
    char * name;
    char content[MAX_SIZE_FILE];
    long int bytes;
};


long int get_size_file(FILE * fp){
    long int size = 0;
    if(!fp) return size;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    return size;
}

struct File * open_file(char * filename){
    struct File * file = (struct File*)malloc(sizeof(struct File));
    if(file){
        file->name = filename;
        FILE * f = fopen(filename, "r");
        if(!f) {
            char message[200];
            sprintf(message, "File not found: %s", filename);
            fatal(message);
        }
            
        file->bytes = get_size_file(f);

        if(file->bytes > MAX_SIZE_FILE) 
            fatal("Max size of file");

        fseek(f, 0L, SEEK_SET);
        fread(file->content, 1, file->bytes, f);
        return file;
    }
    return NULL;
}

void print_file(struct File * file){
    int i;
    for(i = 0; i < file->bytes; i++){
        printf("%c", file->content[i]);
    }
}
