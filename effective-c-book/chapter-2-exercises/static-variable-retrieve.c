#include <stdio.h>
#include <stdlib.h>

static unsigned int counter = 0;

void increment(void){
    counter++;
    printf("Counter now: %d\n", counter);
}

void retrieve(void){
    printf("Counter value from retrieve: %d", counter);
}

int main(){

    for (unsigned int i = 0; i < 5; i++)
    {
        increment();
    }

    retrieve();
    
    return EXIT_SUCCESS;
}