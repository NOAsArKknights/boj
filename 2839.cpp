#include<stdio.h>

int dp[5003];

int main()
{
    int i,n;

    scanf("%d",&n);
    
    dp[3]=dp[5]=1;
    for(i=6;i<=n;i++){
        if(dp[i-3]!=0&&dp[i-5]!=0) dp[i]=(dp[i-3]<dp[i-5])?dp[i-3]+1:dp[i-5]+1;
        else if(dp[i-3]!=0) dp[i]=dp[i-3]+1;
        else if(dp[i-5]!=0) dp[i]=dp[i-5]+1;
    }
    
    if(dp[n]==0) printf("-1\n");
    else printf("%d\n",dp[n]);
    
    return 0;
}
