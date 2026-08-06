//format specifiers 
//it is what it is hehe

// a format specifier that starts with % and then a character that specifes the data type of variable how it is displaed or proccesed

// u can add width , precition flags with format specifiers


#include <stdio.h>
#include <stdbool.h>


int main(){

    // see the codes using format specifiers

    int a=10;
    float b = 7.8;
    double c = 7.89898989;
    char d= 'b';
    char e[]="sup brother ^_^";
    bool f = false ;

    //too ye lo simple usage of format specifiers
    printf("%d \n",a);
    printf("%f \n",b);
    printf("%lf \n",c);
    printf("%c \n",d);
    printf("%s \n",e);
    printf("%d \n",f);


    //with controlling

    int yo = 1;

    //add a num between % and specifier which shows leading spaces

    printf("%1d  \n" , yo );
    //output " 1"
    printf("%2d \n" , yo );
    //output "  1"
    printf("%3d \n" , yo );
    //output "  1"

    //add a negaitve num between % and specifier which shows trailing  spaces


    printf("%-1d \n" , yo );
    //output "1"
    printf("%-2d \n" , yo );
    //output "1 "
    printf("%-3d \n" , yo );
    //output "1  "

    // theses are not spaces the num between % and specifiers defines how many digites will be show
    // by default to full fill digites count it adds spaces at the leading posotion
    // to change the spaces to zero js add zero before the num
    printf("%04d \n" , yo );
    //output "0001"













}
