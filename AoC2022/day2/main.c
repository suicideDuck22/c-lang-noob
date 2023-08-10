#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_play_point(char play[3]){
    char possible_plays[9][3] = {
        "A X", "A Y", "A Z",
        "B X", "B Y", "B Z",
        "C X", "C Y", "C Z",
    };

    int results_points[9] = {
        3, 6, 0,
        6, 3, 0,
        0, 6, 3
    };

    printf("Play: %s\n", play);
    for(int i = 0; i < sizeof(possible_plays); i++){
        printf("Current play looked: %s\n", possible_plays[i]);

        if(play == possible_plays[i]){
            return results_points[i];
        }
    }
}

int main(){
    FILE *fptr;

    fptr = fopen("input.txt", "r");

    if(fptr == NULL){
        perror("Error trying to open the file.");
        exit(1);
    }

    char *my_play = malloc(1);

    int index = 0;

    int max_line_size = 4;
    char line[max_line_size];

    while(fgets(line, max_line_size, fptr)){
        if(index > 0){
            break;
        }

        bool isBreakLine = line[0] == '\n';
        if(isBreakLine){
            continue;
        }

        strcpy(my_play, &line[2]);

        int result_point = get_play_point(line);

        printf("My point on this play: %d", result_point);

        index++;
    }

    free(my_play);
    return 0;
}