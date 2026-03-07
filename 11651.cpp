#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[100003][5];

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;
    
    if(x[1]>y[1]) return 1;
    else if(x[1]<y[1]) return -1;
    else return(x[0]>y[0])?1:-1;
}

int main()
{
    int i,n;

    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d%d",&arr[i][0],&arr[i][1]);
    
    qsort(arr,n,sizeof(arr[0]),cmp);

    for(i=0;i<n;i++) printf("%d %d\n",arr[i][0],arr[i][1]);

    return 0;
}
