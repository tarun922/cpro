#include <stdio.h>
void sort(int L[], int n){
    int i,j;
    int temp=0;
    for(j=0;j<n;j++){
        int z=0;
        for(i=1;i<n;i++){
            if(L[z]>=L[i]){
                temp=L[z];
                L[z]=L[i];
                L[i]=temp;
                z++;
            }
            else{
                z++;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d   ", L[i]);
    }
}


int main(){
    int i,n;
    printf("Enter thr length of an array");
    scanf("%d", &n);
    int L[n];
    printf("Enter values of array");
    for(i=0;i<n;i++){
        scanf("%d", &L[i]);
    }
    sort(L,n);
    return 0;
}
