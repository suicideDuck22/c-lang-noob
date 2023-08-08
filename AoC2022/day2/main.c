#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE *fptr;
    fptr = fopen("input.txt", "r");

    if(fptr == NULL){
        perror("Error trying to open the file.");
        exit(1);
    }

    int max_line_size = 4;
    char line[max_line_size];

    int index = 0;

    while(fgets(line, max_line_size, fptr)){
        bool isBreakLine = line[0] == '\n';
        if(isBreakLine){
            continue;
        }

        printf("Line: %s\n", line);

        char *oponnent_play = malloc(1);
        strcpy(oponnent_play, &line[0]);

        char *my_play = malloc(1);
        strcpy(my_play, &line[2]);

        printf("Opponent play: %c\n", *oponnent_play);
        printf("My play: %c\n\n", *my_play);

        index++;

        free(oponnent_play);
        free(my_play);
    }

    return 0;
}