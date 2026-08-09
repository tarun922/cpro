//while loop in c

#include <stdio.h>

int main(){

    //while loops executes a code until the given condition is true
    /*
    lets se how to use while loop
    it is similar to if statement

    while(urcondition){
    code u want to execute
    easy peezyyy
}

    there are one more type of while loop which is do while

    the difference between while and do while is even tho condition is fasle at starting the
    do while loop executees once no matter
    what is the condition then works same as while loop

    do {
    urcode
}while(condition );

letss se with examples
     */

    //printing num from 1 to 10
    int num=0;
    while (num <= 10){
        printf("%d \n" , num );
        num++;
    }
    // lets try with do while
    int num2 =10 ;
    do{
        printf("see i executd even condition is false once only no matter what is the condition ");
    }while(num2<8);

    // thats it my boys
    return 0;
}
