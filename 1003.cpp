#include<stdio.h>

int arr[43];

int main()
{
    int i,t,n;

    scanf("%d",&t);
    
    arr[1]=arr[0]=1;
    
    for(i=2;i<=40;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    
    while(t--){
        scanf("%d",&n);
        if(n>1) printf("%d %d\n",arr[n-2],arr[n-1]);
        else if(n==1) printf("0 1\n");
        else if(n==0) printf("1 0\n");
    }
    
    return 0;
}
