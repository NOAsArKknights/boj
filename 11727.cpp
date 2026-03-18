#include<stdio.h>

int arr[1003];

int main()
{
    int i,n;
    
    scanf("%d",&n);

    arr[1]=1;
    arr[2]=3;
    
    for(i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]*2;
        arr[i]%=10007;
    }
    
    printf("%d\n",arr[n]);
    
    return 0;
}
