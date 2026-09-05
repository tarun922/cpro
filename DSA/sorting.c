#include <stdio.h>
#include <stdlib.h>
int *sort(int l[] , int n );
int *smerge(int l1[] , int n1,int l2[] , int n2 );
int main(){

    int l1[2]={1,2};
    int n1 = sizeof(l1)/sizeof(l1[0]);
    int l2[2]={3,4};
    int n2 = sizeof(l2)/sizeof(l2[0]);
    int *ss=smerge(l1,n1,l2,n2);
    for (int i =0; i<n1+n2; i++){
        printf("%d ", ss[i]);
    }

    return 0;
}



int *sort(int l[] , int n ){
    int sm=0;
    int ch = 0;
    while (sm<n){
        for (int i =sm ; i < n ;i++ ){
            ch=l[sm];
            if (l[sm]<l[i]){
                l[sm]=ch;
            }
            else{
                l[sm]=l[i];
                l[i]=ch;
            }
        }
        sm+=1;
    }
    return l;

}
;
int *smerge(int l1[] , int n1,int l2[] , int n2 ){
    int *mer = malloc(sizeof(int) * (n1+n2));
    for ( int i =0 ; i< n1+n2 ; i++){
        if (i<n1) mer[i]=l1[i];
        else if ( i<n2+n1)  mer[i]=l2[i-n1];
    }
    return sort(mer , n1+n2);
}
