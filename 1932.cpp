#include<stdio.h>

int arr[503][503],inp[503][503];

int main()
{
    int i,j,n,max=-1;
    scanf("%d",&n);
    
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
           scanf("%d",&inp[i][j]);
           
    arr[1][1]=inp[1][1];       
    for(i=2;i<=n;i++){
        for(j=0;j<=i;j++){
            if(arr[i-1][j-1]<arr[i-1][j]) arr[i][j]=inp[i][j]+arr[i-1][j];
            else arr[i][j]=inp[i][j]+arr[i-1][j-1];    
        }
    }
    
    for(i=1;i<=n;i++){
        if(arr[n][i]>max) max=arr[n][i];
    }
    
    printf("%d\n",max);
    
    return 0;
}
