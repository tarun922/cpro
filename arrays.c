//all about arrays

#include <stdio.h>
#include <sring.g>

int main(){

    //an array is a list of objects having similar data type  either having 1 dimention 2 dimention 3 dimention .......
    // it is  structured and updatable
    //defining a array
    // data type array[]={values ......}
    // let us take an example
    int num[]=[1,2,3,4,5];
    // now what if we want to print num in a array
    // for this u have to do this array[write here the index num of element it starts from 0 ]
    // see how it looks
    // indexing- 0   1   2   3   4
    // array[]={ 1 , 2 , 3 , 4 , 5 }
    // lets print those elements

    printf("%d \n" , num[0]);// output =1
    printf("%d \n" , num[1]);// output =2
    printf("%d \n" , num[2]);// output =3
    printf("%d \n" , num[3]);// output =4
    printf("%d \n" , num[4]);// output =5

    // u can also loop through the values to print it
    // here u can see how we gonna do it
    for (int i = 0 ; i < 5 ; i++){
        printf("%d \n" , num[i]);

    }


    return 0;
}
