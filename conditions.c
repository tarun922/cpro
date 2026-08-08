//conditions -- if else if and else

#include <stdio.h>
#include <stdbool.h>
#include <strings.h>


int main(){


    //c conditions are used to execute a perticular line of code on a specific condition
    // like go to home if it is not raining '' here we can see we go to home only if there is no rain
    // c conditions are same it js usesd to execute some codes
    // nothing serious - don't take tention '

    int age = 0;
    printf("Enter ur age : ");
    scanf("%d",&age);
    //here we are going to check if the person is eligble to vote or not

    if (age == 0 ){ // here u can see we are checking if the person added a age zero which is not actual age
        printf("u havn't been borned yet broo -_-");
    }
    //now lets check the age must be greater then zero
    else if (age <= 0 ){
        printf("enter a positive age  ");
    }
    //now lets check if age is more then 18 then ur eligble for voting
    else if (age >=18){
        printf("u are eligble for vote ");
    }
    // now else don't take any condition it handles all rest cases soo if any other case happens the user is not eligble for vote '
    else {
        printf("u are not eligble for vote ");

    }
    // that's it for conditions now go and try out urself it easy friends '
    return 0;
}
