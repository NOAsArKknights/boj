#include<stdio.h>

int arr[303],dp[303][5];

int main()
{
    int i,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=0;i<n;i++){
        dp[i][0]=dp[i][1]=arr[i];
        if(i>=2){
            if(dp[i-2][1]>dp[i-2][0]) dp[i][0]+=dp[i-2][1];
            else dp[i][0]+=dp[i-2][0];
        }
        dp[i][1]+=dp[i-1][0];
    }
    
    if(dp[n-1][0]>dp[n-1][1]) printf("%d\n",dp[n-1][0]);
    else printf("%d\n",dp[n-1][1]);
    
    return 0;
}
