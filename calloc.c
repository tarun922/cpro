//calloc

#include <stdio.h>
#include <stdlib.h>


int main(){

    // calloc = it takes 2 args, 1st num, and second how much space for each element,
    // and it initialises all the elements to 0 (zero-initialized memory)
    // which is the main difference between malloc and calloc
    // both are same, just calloc initialises all elements to 0
    //usage
    int *numbs=calloc(5,sizeof(int));

    for (int i=0; i<5 ; i++){

        printf("enter num for subject %d : " , i+1);
        scanf("%d",&numbs[i]);

    };
    printf("all numbers added succesfully ");
    free(numbs);

    numbs=NULL;
    return 0;


}
