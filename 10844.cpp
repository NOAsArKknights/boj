#include<stdio.h>

int dp[103][13];

int main(){

    int i,j,n,cnt=0;
    
    scanf("%d",&n);

    for(i=1;i<10;i++){
        dp[1][i]++;
    }
    
    for(i=2;i<=n;i++){
        for(j=0;j<10;j++){
            if(j==0) dp[i][j]+=dp[i-1][j+1];
            else if(j==9) dp[i][j]+=dp[i-1][j-1];
            else dp[i][j]+=dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j]%=1000000000;
        }
    }

    for(i=0;i<10;i++){
        cnt+=dp[n][i];
        cnt%=1000000000;
    }    

    printf("%d\n",cnt);

    return 0;
}
