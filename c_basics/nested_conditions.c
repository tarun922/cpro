//nested_conditions

#include <stdio.h>
#include <string.h>
int main(){
    // nested conditions u can use when u want to add more conditions in a if block lets see the example
    // we are going to check if the user is male or female then we check if they minor or adult
    // here we go again
    int age =0;
    char gen[10]="";

    printf("Enter your gender (male / female ) : ");
    scanf("%s" , &gen );

    getchar();
    printf("enter your age : ");
    scanf("%d" , &age );
    if (strcmp(gen, "male") == 0) {
        printf("you are male ");
        if (age <=0 ){// here we added a nested condition in the if statement it checks the age and validate it
            printf("enter a valid age ");

        }
        else if (age >=18 ){
            printf("you are adult   ");

        }
        else if (age < 18 ){
            printf("you are minor    ");

        }
    }
    //  to compare strings usee strcmp(urstring , string u want to compare ) it returns 0 or 1 false / true
    else if (strcmp(gen, "female") == 0) {
        printf("you are female ");
        if (age <=0 ){
            printf("enter a valid age ");

        }
        else if (age >=18 ){
            printf("you are adult   ");

        }
        else if (age < 18 ){
            printf("you are minor    ");

        }
    }


    return 0;

}
