#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *ifinder(char **str , int size);
char *cmp(char **str , int size);

int main(){
    char *j[]={"a"};
    int mm=sizeof(j)/sizeof(j[0]);
    /*
    int* n = ifinder(j,mm);
    for (int i =0 ;i < 2; i++ ){
        printf("%d " , n[i]);
    }*/
    char *sf=cmp(j,mm);
    printf("%s" , sf);
    return 0;
}
;
int *ifinder(char **str , int size){

    int s=0;
    int inx=0;
    int sz=0;
    while(s<size-1){
        if ( strlen(str[inx]) <=  strlen(str[s+1])) {
            inx=inx;
            sz=strlen(str[inx]);
        }
        else if ( strlen(str[inx]) >  strlen(str[s+1])) {
            inx=s+1;
            sz=strlen(str[s+1]);
        }
        s+=1;

    }
    int *m=malloc(2*sizeof(int));
    m[0]=inx;
    m[1]=sz;
    return m;
}
;
char *cmp(char **str , int size){
    //char *stm;
    int *jj=ifinder(str , size);
    char *stm = malloc(jj[1] + 1);
    for (int i =0 ; i<jj[1] ;i++){
        int ch=0;
        for (int k = 0 ; k<size ;k++){
            if (k!= jj[0]){
                if ( str[jj[0]][i]== str[k][i]){
                    ch=1;
                }else{
                    ch=0;
                }
            }
        }
        if (ch==0 && i ==0){
            return "There is no common prefix among the input strings.";
        }else if (ch==1){
            stm[i]=str[jj[0]][i];
        }else{
            break;
        }
    }
    stm[jj[1]] = '\0';
    return stm;

}
