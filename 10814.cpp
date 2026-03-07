#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[100003][5];
char str[100003][103];

int cmp(const void *a,const void *b){
    const int *x = (const int*)a;
    const int *y = (const int*)b;
    
    if(x[0]>y[0]) return 1;
    else if(x[0]<y[0]) return -1;
    else return 0;    
}

int main()
{
    int i,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%d",&arr[i][0]);
        scanf("%s",&str[i]);
        arr[i][1]=i;
    }
    
    qsort(arr,n,sizeof(arr[0]),cmp);
    
    for(i=0;i<n;i++){
        printf("%d %s\n",arr[i][0],str[arr[i][1]]);
    }
    
    return 0;
}
