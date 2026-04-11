#include<stdio.h>

int arr[10003],dp[10003][5];

int mx(int x,int y){ return(x>y)?x:y;}

int main(){

    int i,n,max=-1;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    dp[0][1]=arr[0];
    dp[1][0]=dp[0][1];
    dp[1][1]=arr[1],dp[1][2]=dp[0][1]+arr[1];
    for(i=2;i<n;i++){
        dp[i][0]=mx(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=mx(dp[i-2][2],mx(dp[i-2][0],dp[i-2][1]))+arr[i];
        dp[i][2]=dp[i-1][1]+arr[i];
    }
    max=mx(dp[n-1][0],mx(dp[n-1][1],dp[n-1][2]));
    
    printf("%d\n",max);

    return 0;
}
