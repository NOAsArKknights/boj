#include<stdio.h>

int arr[1003][3],dp[1003][3];

int main()
{
   int i,n,max=1000001;

   scanf("%d",&n);
   
   for(i=0;i<n;i++) scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
       
   for(i=1;i<n;i++){
       if(arr[i-1][0]<arr[i-1][1]) arr[i][2]+=arr[i-1][0];
       else arr[i][2]+=arr[i-1][1];
       if(arr[i-1][0]<arr[i-1][2]) arr[i][1]+=arr[i-1][0];
       else arr[i][1]+=arr[i-1][2];
       if(arr[i-1][1]<arr[i-1][2]) arr[i][0]+=arr[i-1][1];
       else arr[i][0]+=arr[i-1][2];
   }
   
   if(max>arr[n-1][0]) max=arr[n-1][0];
   if(max>arr[n-1][1]) max=arr[n-1][1];
   if(max>arr[n-1][2]) max=arr[n-1][2];
   
   printf("%d\n",max);
   
   return 0;
}
