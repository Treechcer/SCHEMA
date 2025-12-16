#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool writeOpen(char name[], char fileText[]){
    FILE* fptr;
    fptr = fopen(name, "w");

    if (fptr == NULL){
        return false;
    }

    fprintf(fptr, fileText);

    return true;
}