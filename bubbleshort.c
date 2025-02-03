#include<stdio.h>
#define SIZE 9 

int main(){

    // int a[] ={ 76,54	,34	,46	,76	,65	,54	,98	,90}; 
    int a[] = {9,8,7,6,5,4,3,2,1};
    int i,j,tmp,x; 
    int swap=0; 


    printf("\nArray before sort\n");
    for(i=0;i<SIZE;i++){
        printf(" %d",a[i]);
    }

    for(i=0;i<SIZE-1;i++){ // 8 
        swap =0;
        for(j=0;j<SIZE-1;j++){ // j < 8  => 7  
            if(a[j] > a[j+1]){
                swap =1 ;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp; 
            }
        }//pass 1  
        if(swap == 0){
            break; 
        }
        printf("\nPass %d\n",i+1); //
          for(x=0;x<SIZE;x++){
            printf(" %d",a[x]);
        } 
    }

    printf("\nArray after sort\n");
    for(i=0;i<SIZE;i++){
        printf(" %d",a[i]);
    }

    return 0;
}