#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1000003][5];

int cmp1(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;    
    
    return x[0]-y[0];
}
int cmp2(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;    
    
    return x[1]-y[1];
}

int main()
{
    int i,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
        arr[i][1]=i;
    }
    
    qsort(arr,n,sizeof(arr[0]),cmp1);
    
    for(i=1;i<n;i++){
        if(arr[i][0]>arr[i-1][0]) arr[i][2]=arr[i-1][2]+1;    
        else arr[i][2]=arr[i-1][2];
    }
    
    qsort(arr,n,sizeof(arr[0]),cmp2);
    
    for(i=0;i<n;i++) printf("%d ",arr[i][2]);
    
    return 0;
}
