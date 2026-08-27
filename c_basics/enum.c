//enum
#include <stdio.h>



enum status{
    pass,fail
};



int main(){
    //enums = are user defined data types which consists a set of named integers
    // befifits : replaces numbers with readble names

    enum status check=fail;

    switch(check){
        case pass:
            printf("u passed ");
            break;
        case fail:
            printf("u failed");
            break;

    }

}
