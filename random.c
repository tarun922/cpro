// generating random numbers

// we gonnna use stdlib.h and time.h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    // we are going to get pseudo random number using a maths formla
    // seeding our random num using current time so it every thime changes

    srand(time(NULL));
    // seeting maximum and minum value the our random num can have
    int min = 10 ;
    int max = 20 ;
    int randomN=(rand() % (max - min +1 )) + min ;
    printf("%d" , randomN);

    // that's it there are many more ways to generete ramdoom num and in much more better randomnes but '
    // its the easiest one
    return 0;
}
