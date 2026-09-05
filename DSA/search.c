#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int *mc(int *num , int size );
int **pos(int *num , int size );
int *dis(int *num , int size );
bool check(int* s ,int n , int num );
int minn(int *num , int size);
void play(int **n, int l){
    for (int i =1 ; i<l ; i++){
        for (int k =0 ; k<3 ; k++){
            printf("%d " , n[i][k] );
        }
        printf("\n");

    }
}
void po(int *n , int l ){
    for (int i = 1 ; i < l ; i++){
        printf("%d " , n[i]);
    }
}
int main(){
    int n[] =  {1,1,2,3,2,1,2};
    int s = sizeof(n)/sizeof(n[0]);
    /*
    int **h=pos(n,s);
    if (h[1][0]==-1){
        printf("%d " , -1);
    }else play(h , h[0][0]+1);
*/
    int m = minn( n , s  );
    printf("%d" , m);
    return 0;
}

bool check(int* s ,int n , int num ){
    bool v = false;
    for (int i =1; i<n ; i++){
        if ( s[i] == num ){
            v=true;
            break ;
        }
    }
    return v;
}

int *mc(int *num , int size ){

    int *mtc= malloc((size+1)*sizeof(int));
    mtc[0]=0; // first element tels the lenght of the founded array
    mtc[1]=-1;
    int i = 0;
    int v=1;
    for (i ; i < size ; i++){
        int co=0;
        for ( int j = 0 ; j < size ; j++ ){
            if (num[i]==num[j]){
                co+=1;
            }else{
                continue;
            }

        }
        if (co==3 && !check(mtc , v, num[i])){
            mtc[v]=num[i];
            mtc[0]+=1;
            v+=1;


            continue;
        }else{
            co=0;
        }
    }
    int *temp = realloc(mtc, (v) * sizeof(int));
    if (temp != NULL) mtc = temp;
    return mtc;

}

int **pos(int *num , int size ){
    int *tn= mc(num , size );

    if (tn[1]==-1){
        int **temp = malloc(2*sizeof(int*));
        temp[0] = malloc(1*sizeof(int));
        temp[1] = malloc(1*sizeof(int));
        temp[0][0]=tn[0];
        temp[1][0] = -1;
        return temp;
    }
    int **pp = malloc((tn[0]+1)*sizeof(int*));
    pp[0]=malloc(1*sizeof(int));
    pp[0][0]=tn[0];

    for (int k =1 ; k <= tn[0] ; k++ ){
        pp[k]=malloc(3*sizeof(int));
        int c=0;
        for (int i = 0 ; i < size ; i++){
            if(num[i]==tn[k]){
                if (c==3) break ;
                pp[k][c]=i;
                c+=1;

            }
        }
    }
    return pp;

}
;

int *dis(int *num , int size ){
    int **ppl = pos(num , size );
    if (ppl[1][0]==-1){
        int *tp =malloc(1*sizeof(int));
        tp[0]=-1;
        return tp;
    }

    int *v = malloc((ppl[0][0]+1)*sizeof(int));
    v[0]=ppl[0][0];
    for ( int i = 1 ; i <= ppl[0][0] ; i++ ){
       v[i] = abs(ppl[i][0]-ppl[i][1]) + abs(ppl[i][1]-ppl[i][2]) + abs(ppl[i][2]-ppl[i][0]);

    }


    return v;
}

int minn(int *num , int size){
    int *vv = dis(num , size);
    if (vv[0]==-1){
        return -1;
    }
    int min = vv[1];
    for ( int i =1 ; i < vv[0]+1 ; i++ ){
        if (min >= vv[i]){
            min=vv[i];
        }
    }
    return min;
}
