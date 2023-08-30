#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// A - X = PEDRA - PEDRA = EMPATE = 3;
// A - Y = PEDRA - PAPEL = GANHOU = 6;
// A - Z = PEDRA - TESOURA = PERDEU = 0;

// B - X = PAPEL - PEDRA = PERDEU = 0;
// B - Y = PAPEL - PAPEL = EMPATE = 3;
// B - Z = PAPEL - TESOURA = GANHOU = 6;

// C - X = TESOURA - PEDRA = GANHOU = 6;
// C - Y = TESOURA - PAPEL = PERDEU = 0;
// C - Z = TESOURA - TESOURA = EMPATE = 3;

int get_my_throw_point(char throw[1]){
    char *my_plays[] = {"X", "Y", "Z"};
    for(int i = 0; i <= sizeof(my_plays[0]); i++){
        if(strcmp(throw, my_plays[i]) == 0){
            return i + 1;
        }
    }
}

char *get_my_throw(char elf_code[1], char opponent_play[1],char need[4]){
    printf("Na function: %s\n", opponent_play);
    char *opponent[] = {"A", "B", "C"};

    char *to_won[] = {"Y", "Z", "X"};
    char *to_draw[] = {"X", "Y", "Z"};
    char *to_lose[] = {"Z", "X", "Y"};

    for(int i = 0; i <= sizeof(opponent[0]); i++){
        if(strcmp(opponent_play, opponent[i]) == 0){
            
            if(strcmp(need, "LOSE") == 0){
                return to_lose[i];
            } else if(strcmp(need, "WON") == 0){
                return to_won[i];
            } else {
                return to_draw[i];
            }
        }
    }

    return NULL;
}

int main(){
    FILE *fptr;

    fptr = fopen("input.txt", "r");

    if(fptr == NULL){
        perror("Error trying to open the file.");
        exit(1);
    }

    int final_result = 0;
    char *my_play = malloc(1);

    int max_line_size = 4;
    char line[max_line_size];

    while(fgets(line, max_line_size, fptr)){
        bool isBreakLine = line[0] == '\n';
        if(isBreakLine){
            continue;
        }

        int result_point = 0;

        char opponent_play = line[0];
        char elf_code = line[2];

        printf("Aqui: %c\n", &opponent_play);

        if(strcmp(&elf_code, "X") == 0){
            strcpy(my_play, get_my_throw(&elf_code, &opponent_play, "LOSE"));
            result_point = 0;
        } else if(strcmp(&elf_code, "Z") == 0){
            strcpy(my_play, get_my_throw(&elf_code, &opponent_play, "WON"));
            result_point = 6;
        } else {
            strcpy(my_play, get_my_throw(&elf_code, &opponent_play, "DRAW"));
            result_point = 3;
        }

        int throw_point = get_my_throw_point(my_play);

        final_result += result_point + throw_point;
    }

    printf("Final result: %d", final_result);
    free(my_play);

    fclose(fptr);
    return 0;
}