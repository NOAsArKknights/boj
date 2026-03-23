#include<stdio.h>

int dp[253][1003];

int main(){

    int i,j,n,len;
    
    dp[0][0]=1,dp[1][0]=1,dp[2][0]=3;
    for(i=3;i<=250;i++){
        for(j=0;j<1003;j++){
            dp[i][j]+=dp[i-1][j]+dp[i-2][j]*2;
            if(dp[i][j]>=10){
                dp[i][j+1]+=dp[i][j]/10;
                dp[i][j]%=10;
            }
        }
    }
    while(scanf("%d",&n)==1){
        len=1000;
        while(len>0&&dp[n][len]==0) len--;
        for(i=len;i>=0;i--) printf("%d",dp[n][i]);
        printf("\n");
    }
    
    return 0;
}
