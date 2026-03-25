#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[1000003];

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;

    return *y-*x;
}

int main()
{
    int i,n,m,cnt=1,p=0;
    long long tmp=0;

    scanf("%d%d",&n,&m);    
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(int),cmp);
    
    for(i=1;i<n;i++){
        if(tmp+i*(arr[i-1]-arr[i])<=m) tmp+=i*(arr[i-1]-arr[i]);
        else break;
        cnt++;
    }

    while(1){
        if(tmp>=m) break;
        tmp+=cnt;
        p++;
    }
    
    printf("%d\n",arr[cnt-1]-p);
    
    return 0;
}
