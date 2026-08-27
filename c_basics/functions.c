// functions in c

#include <stdio.h>
#include <string.h>


// functions a reusable blocks of code that u can use again and again

// to define a function js define its return type and ur function came (){} boom u defined ur fuunction
// here u can see a example

// void --means it returns nothing
// int --it reaturns integer
// float it reutrns a float value
// bool it returns a boolean value true false
//
// defining a function


// void addition( pass parameters here how many u want like  int a , int b ....... ){
//    int z= a+b;
//    printf("%d" , z );
//
//}

//lets define it

void addition(int a , int b ){
    int z = a+b;
    printf("%d \n" , z );// it prints addition of 2 nums now go to up and see caaling a function
}

//lets define a subtraction function too
void subtraction(int a , int b ){
    int z = a-b;
    printf("%d \n" , z );// it prints addition of 2 nums now go to up and see caaling a function
}

int main(){

    // lets call our fuunction more then 1 time
    addition(20,45);
    //output 65
    addition(80,5);
    //output 85
    addition(60,40);
    //output 100

    //subtraction
    subtraction(50, 40);
    //output 10
    subtraction(40,70);
    //output -30
    return 0;
}


