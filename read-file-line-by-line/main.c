#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE *fptr;

    fptr = fopen("./input.txt", "r");

    if(fptr == NULL){
        fprintf(stderr, "Not able to open this file.");
        exit(1);
    }

    int sum = 0;
    int minor = 0;
    int major = 0;

    int maxLineSize = 100;
    char line[maxLineSize];

    int index = 0;
    while(fgets(line, maxLineSize, fptr)){
        bool isLineEmpty = line[0] == '\n';
        if(isLineEmpty == true){
            continue;
        }

        int intLine = atoi(line);
        
        if(intLine > major){
            major = intLine;
        }

        sum += intLine;

        if(index == 0){
            minor = intLine;
            index++;
            continue;
        }

        if(intLine < minor){
            minor = intLine;
        }

        index++;
    }

    double average = sum / (index + 1);

    printf("Major number: %d\n", major);
    printf("Minor number: %d\n", minor);
    printf("Sum of the numbers: %d\n", sum);
    printf("Average: %.2f\n", average);
    return 0;
}