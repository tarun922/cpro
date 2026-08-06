#include <stdio.h> // including input and output functions

#include <stdbool.h> // this is to include bool realted functions

// bhaio aur bheno this is notes l1 -- variables -d -f -lf
// to run a cpp or c code make sure u have installed gcc through mingw or mysys2

// step 1 open terminal
// step 2 change directory to ur current folder like this cd "path"
// step 3 type  gcc urfilename.c -o urfilename.exe if u on windows else use gcc urfilename.c -o urfilename
// for cpp code js do this g++ urfilename.cpp -o urfilename.exe
// step 4 type urfilename.exe hit enter boom code runned
int main(){

     //to use specifier use %specifier like d , f , lf etcetc and yup in printing
     // type printf("%specifier_for_the_variable_1 , %specifier_for_the_variable_2 ....  " ,variable_1,variable_2 ....  )
     // all varible will go to there specifier through ppointer vice respectivly

     //int
    //so the int variable only storest integer and the specifier to display it is %d  , u can see a example here

    int a =10;
    printf(" %d \n" , a);

    //float
    //so the float variable is bacically decimal varible and only have 6-7 decimal point values its specifier to display it is %f , u can see example
    float  b =20.123456;

    printf("  %.6f \n" , b);
    // u can specify how many digits after the decimal in double or float to be visible or showed by js addin %.digits-then specifier like %.4f

    //double
    //so a double is extended format of float having 16 decimal values its specifier is %lf , u can see example
    double c = 20.1234567890123456;
    printf(" %.16lf \n " , c);
    //char
    //so a char is a character type varible only single charachter or symbol can be stored its specifier is @c , u can see example

    char d ='A' ;//single qoutes for char
    printf(" %c \n" , d );


    //hmmmmm
    //string
    //to store a string u can say ur txt lines use char varible[] now u can store multiple charachter in a variable called string its specifier if @s u can see example here ,
    char name[]="aur bhai kaisa hai " ;  //double qoutes for variables

    printf(" %s \n" , name )

    //bool
    //so bools are basically condition varibles its specifer is also %d becuse it basically show's 0,1 false,true respectivly '
    //ucan see a working example here
    bool isworking = true ; // u can use (true,1) both means same and (false,0) both means same
    printf("%d \n" , isworking )
    printf("")


    return 0;
}
