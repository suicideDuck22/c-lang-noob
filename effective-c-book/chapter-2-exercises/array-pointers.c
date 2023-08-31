#include <stdlib.h>
#include <stdio.h>

void first(void){
    printf("Calling the first function on index 0.\n");
}

void second(void){
    printf("Calling the second function on index 1.\n");
}

void third(void){
    printf("Calling the third function on index 2.\n");
}

void call(int index){
    void (*funcs[3]) () = {&first, &second, &third};
    funcs[index]();
}

int main(void){
    call(2);
    call(0);
    call(1);

    return EXIT_SUCCESS;
}