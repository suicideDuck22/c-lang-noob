#include <stdlib.h>
#include <stdio.h>

void swap(int *pa, int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;

    printf("Swap: a = %d, b = %d\n", *pa, *pb);
};

int main(){
    int a = 21;
    int b = 17;

    swap(&a, &b);
    printf("Main: a = %d, b = %d", a, b);
    return EXIT_SUCCESS;
}