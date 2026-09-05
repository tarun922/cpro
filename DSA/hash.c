#include <stdio.h>
#include <stdlib.h>
#define Length 100
typedef struct {
    int num ;
    int indx;
}NUM;

typedef struct{
    NUM *numbs ;
    int size ;
}Colloction;


int map_f(Colloction nbs , int num );
int map_d(Colloction *nbs , int num ,int indx );
int hash(int num ){
    int h = num%Length ;
    if (  h < 0 ) h += Length;
    return h ;
}
int main(){
    int n[]= { 100, 70 , 2,3,4, 50 };
    int size = sizeof(n)/sizeof(n[0]);
    int v = 150;
    Colloction C ;
    C.size = 0;
    C.numbs= malloc(Length*sizeof(NUM));

    for (int i = 0 ; i < size ;i++ ){
        if ( map_f(C , v-n[i]  ) != -1 ){
            printf("%d , %d " , i , map_f(C , v-n[i]  ));
            break;
        }else{
            map_d(&C , n[i] , i );
        }

    }

    return 0;
}
/*
int map_f(Colloction nbs , int num  ){
    for (int i =0 ; i < nbs.size ; i++){
        if (nbs.numbs[i].num == num ){
            return nbs.numbs[i].indx;
        }
    }
    return -1;
}*/
int map_f(Colloction nbs , int num  ){
    int b = hash(num);
    if ( nbs.numbs[b].num == num ){
        return nbs.numbs[b].indx;
    }
    return -1;
}
int  map_d(Colloction *nbs , int num , int indx  ){

    int b = hash(num);

    nbs->numbs[b].num = num;
    nbs->numbs[b].indx =  indx ;
    nbs->size+=1;
    return 0;


}
