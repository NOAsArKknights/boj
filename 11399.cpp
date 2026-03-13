#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1003];

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;
    
    if(*x>*y) return 1;
    else if(*x<*y) return -1;
    else return 0;
}

int main()
{
    int i,n,cnt=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    qsort(arr,n,sizeof(int),cmp);

    for(i=0;i<n;i++){
        cnt+=arr[i]*(n-i);
    }    
    
    printf("%d\n",cnt);
    
    return 0;
}
