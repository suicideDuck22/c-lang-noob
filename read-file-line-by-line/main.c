#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fptr;

    fptr = fopen("./input.txt", "r");

    if(fptr == NULL){
        fprintf(stderr, "Not able to open this file.");
        exit(1);
    }

    int lines[20];

    int max_line_size = 100;
    char line[max_line_size];

    int index = 0;
    while(fgets(line, max_line_size, fptr)){
        if(strlen(line) == 0){
            printf("EMPTY LINE FOUNDED AT INDEX %d", index + 1);
        }

        lines[index] = atoi(line);
        index++;

        printf("%s", line);
    }



    return 0;
}