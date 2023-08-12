#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int get_my_throw_point(char throw[1]){
    char *my_plays[] = {"X", "Y", "Z"};
    for(int i = 0; i <= sizeof(my_plays[0]); i++){
        if(strcmp(throw, my_plays[i]) == 0){
            return i + 1;
        }
    }
}

// A - X = PEDRA - PEDRA = EMPATE = 3;
// A - Y = PEDRA - PAPEL = GANHOU = 6;
// A - Z = PEDRA - TESOURA = PERDEU = 0;

// B - X = PAPEL - PEDRA = PERDEU = 0;
// B - Y = PAPEL - PAPEL = EMPATE = 3;
// B - Z = PAPEL - TESOURA = GANHOU = 6;

// C - X = TESOURA - PEDRA = GANHOU = 6;
// C - Y = TESOURA - PAPEL = PERDEU = 0;
// C - Z = TESOURA - TESOURA = EMPATE = 3;

int get_play_point(char play[3]){
    char *possible_plays[] = {
        "A X", "A Y", "A Z",
        "B X", "B Y", "B Z",
        "C X", "C Y", "C Z"
    };

    int results_points[] = {
        3, 6, 0,
        0, 3, 6,
        6, 0, 3
    };

    for(int i = 0; i <= sizeof(possible_plays[0]); i++){
        if(strcmp(play, possible_plays[i]) == 0){
            return results_points[i];
        }
    }

    printf("Not found: %s\n", play);
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
    int final_result = 0;
    char line[max_line_size];

    while(fgets(line, max_line_size, fptr)){
        bool isBreakLine = line[0] == '\n';
        if(isBreakLine){
            continue;
        }

        strcpy(my_play, &line[2]);

        int result_point = get_play_point(line);
        int throw_point = get_my_throw_point(my_play);

        final_result += result_point + throw_point;
    }

    printf("Final result: %d", final_result);

    free(my_play);
    fclose(fptr);
    return 0;
}