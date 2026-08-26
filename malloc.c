#include <stdio.h>
// using stdlib library to use malloc

#include <stdlib.h>


int main(){

    // malloc = it helps to create a specific amount of space to work on
    //"malloc = mujhe heap se X bytes ki jagah do,
    //       aur uska address (pointer) de do, taaki main manually use kar sakoon"

    int *marks= malloc(5*sizeof(int));

    for (int i = 0 ; i< 5 ; i++){
        printf("enter %d subject number : " , i+1 );
        scanf("%d", &marks[i]);

    };
    printf("all five subjects marks are stored ");
    //its important to free up space and set pointer to null after completing work
    free(marks);
    marks=NULL;
    // thats it for malloc its easy don't complicate it '
    return 0;
}

