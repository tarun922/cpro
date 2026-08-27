//userinput
#include <stdio.h> // standard input output streams
#include <strings.h> //for string realted tasks

int main(){
    //define variables first and give them there least value else it will behaves weird
    int age =0 ;
    float cgpa = 0.0f;
    char name[40] = "";

    printf("Enter ur age : "); // add txt u want to show for asking the variables values
    scanf("%d" , &age ); // i graps all the txt and saves in ur variables


    printf("Enter ur cgpa :");
    scanf("%f" , &cgpa);

    getchar(); //it clears \n buffers  soo it dosn't mess with next input '
    printf("Enter ur name :");
    fgets(name , sizeof(name), stdin ); // it graps all txt including spaces so u can get long txts and best for strings


    printf("ur name is %s \n ur age is %d \n ur cgpa is %f" , name , age , cgpa );

    return 0;

}
