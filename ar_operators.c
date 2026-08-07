#include <stdio.h>
//arithmetic operators -> {+,-,*,/,++,--,%}

int  main(){
    int a=10;

    int b=20;

    int z = 0;

    //adition
    z=a+b;
    printf("%d  \n" , z); //outpput will be a integer which is 30

    //subtraction

    z=b-a;
    printf("%d \n", z ); //output will be an integer which is 10


    //multiplication

    z=a*b;
    printf("%d \n", z ); //output will be an integer which is 200

    // division hhere things messed up
    // in order to get proper decimal values u have to change one of the int to float soo ur output contains floating point values
    // also store in a floating variable
    float c = 20;
    float d =0;
    d= a/c;
    printf("%f \n", d ); //output will be an float  which is 0.5000

    //modulus it gives us reminder

    int f = 3;
    z= b%f;
    printf("%d \n", z ); //output will be an integer which is 2

    //increment and decrement by 1

    a++; //incremented by 1
    printf("%d \n", a ); //output will be an integer which is 11

    a--; //decremented by 1
    printf("%d \n", a ); //output will be an integer which is 10

    //argumented asignment operators
    //if u reasigning the value to same variable

    int x= 6;

    x+=1; //it is x=x+1
    x-=1; // it is x=x-1
    x*=2; // it is x=x*2
    x/=2; // it is x=x/2

    //thats it for arithmetic operators , ^_^




    return 0;
}
