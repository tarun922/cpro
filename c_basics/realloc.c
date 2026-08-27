//realloc

#include <stdio.h>
#include <stdlib.h>

int main(){

    //realloc = its helps u to re allocate memory to ur previously created malloc / calloc

    int *numbs=malloc(3*sizeof(int));

    //using realloc to allocate a total of 5 int spaces

    int *temp = realloc(numbs, 5 * sizeof(int));
    if (temp == NULL) {
        // realloc fail hua, arr abhi bhi valid hai, use free kar sakte ho
        free(numbs);
    } else {
        numbs = temp; // safe reassignment
    }

    for (int i=0; i<5 ; i++){

        printf("enter num for subject %d : " , i+1);
        scanf("%d",&numbs[i]);

    };
    printf("all numbers added succesfully ");
    free(numbs);

    numbs=NULL;

    return 0;
}
