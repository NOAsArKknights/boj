#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;
    
    if(x[1]==y[1]) return x[2]-y[2];
    return x[1]-y[1];
}

int arr[20][3],dp[10003];

int main(){

    int i,j,n,d;
    
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++) scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);

    qsort(arr,n,sizeof(arr[0]),cmp);

    for(i=1;i<=d;i++){
        dp[i]=dp[i-1]+1;
        for(j=0;j<n;j++){
            if(arr[j][1]==i&&dp[i]>dp[arr[j][0]]+arr[j][2]){
                dp[i]=dp[arr[j][0]]+arr[j][2];
            }
        }
    }

    printf("%d\n",dp[d]);

    return 0;
}
