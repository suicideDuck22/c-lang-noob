#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if(index == 1){
            break;
        }

        printf("%s", &line[0]);

        char oponnent_play[1];
        strcpy(oponnent_play, (char *)&line[0]);

        char my_play[1];
        strcpy(my_play, (char *)&line[2]);

        printf("Opponent play: %s\n", oponnent_play);
        printf("My play: %s\n\n", my_play);

        index++;
    }

    return 0;
}