#include <stdio.h>

#include <stdlib.h>

typedef struct {
    int *pre;
    int *suf;
}NUM;
void min( NUM *ni , int *j, int s );
void max( NUM *ni , int *j, int s );
int check(NUM *n ,  int s , int tar );

int main(){
    int arr[] = { 0,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    NUM val;
    val.suf = malloc(len*sizeof(int));
    val.pre = malloc(len*sizeof(int));

    min(&val  , arr , len );
    max(&val  , arr , len );
    int j = check(&val , len , 0);
    printf("%d " , j );
    return 0 ;
}
void min( NUM *n , int *j, int s ){
    n->suf[s-1] =  j[s-1] ;
    for (int i =s-2 ; i >= 0 ; i-- ){
        if ( n->suf[i+1] > j[i] ){
            n->suf[i] = j[i];
        }else{
            n->suf[i]=n->suf[i+1];
        }

    }

}

void max( NUM *n , int *j, int s ){
    n->pre[0] =  j[0] ;
    for (int i =1 ; i < s ; i++){
        if ( n->pre[i-1] < j[i] ){
            n->pre[i] = j[i];
        }else{
            n->pre[i]=n->pre[i-1];
        }

    }

}
int check(NUM *n , int s, int tar ){
    for ( int i = 0 ; i < s ; i++){
        int t = n->pre[i]-n->suf[i];
        if (t <= tar  ){
            return i ;
        }
    }


    return -1;
}
