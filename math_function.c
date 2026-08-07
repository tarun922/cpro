//math functions

#include <stdio.h>
// adding maths functions header file

#include <math.h>
#include <stdlib.h>
int main (){

    int x= 9;
    float y=9.98;

    //power function

    x= pow(x,2);
    //its x raise to the power 2

    printf("%d  \n",x);

    //square root function

    x=sqrt(x);
    printf("%d \n",x);

    //rounding off to nearest value

    y=round(y);
    printf("%f \n",y);

    y=7.88;
    // rounding up to the next nearest integer
    y=ceil(y); //output will be 8
    printf("%f \n",y);

    //rounding down to the preciding nearest integer

    y=7.99;

    y=floor(y); // output will be 7


    //absolute value -- positive value always like mod in 12th maths
    x= -6;
    x=abs(x);
    printf("%d \n",x); //output will be 6

    // natural log
    x=log(x);
    printf("%d \n",x);

    //trigo sin cos tan

    //input must be in radians
    y=55;
    y=sin(y);
    printf("%f \n",y);



    // thats it some usefull maths functions


    return 0;

}
