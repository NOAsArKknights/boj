#include<stdio.h>

int arr[100003],dp[100003];

int mx(int x,int y){ return(x>y)?x:y;}

int main(){

    int i,n,res=-20001;
    
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        dp[i]=mx(arr[i]+dp[i-1],arr[i]);
        res=mx(res,dp[i]);
    }

    printf("%d\n",res);

    return 0;
}
