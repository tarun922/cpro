//sitches in c

#include <stdio.h>

int main(){
    //switches are similar to if else statments but more better when u comparing num or characters

    // here are example usage of switches

    int month = 0;
    printf("enter a month number  from 1-12 : ");
    scanf("%d" , &month );
    // here we are going to print what month is it

    switch(month ) {// in switch brackets () the variable goes which u want to compare
        case 1:  // add the num or char that is u want to compare in out case the numbs are from 1-12
            printf("jan ");
            break ;//break is imp to escape out throught switch if not added
            // then all are next cases auto runs
            // make sure to add break in each case

        case 2:
            printf("feb ");
            break ;

        case 3:
            printf("march");
            break ;

        case 4:
            printf("april ");
            break ;

        case 5:
            printf("may ");
            break ;

        case 6:
            printf("june");
            break ;

        case 7:
            printf("july ");
            break ;

        case 8:
            printf("aug");
            break ;

        case 9:
            printf("sept ");
            break ;

        case 10:
            printf("oct ");
            break ;

        case 11:
            printf("nov ");
            break ;

        case 12:
            printf("dec");
            break ;

        default:// this is default case if user entered a wrong value which is not in ur cases
            printf("please enter a num between 1 to 12");
            break ;


    }
    // that's it for switches now go and try somthing crazy by urself '
    return 0;


}
