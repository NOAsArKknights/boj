#include<stdio.h>

int arr[1000003];

int main()
{
    int i,n;

    scanf("%d",&n);
    
    for(i=2;i<=n;i++){
        if(i%3==0){
            if(arr[i]>arr[i/3]+1||arr[i]==0) arr[i]=arr[i/3]+1;
        }
        if(i%2==0){
            if(arr[i]>arr[i/2]+1||arr[i]==0) arr[i]=arr[i/2]+1;
        }
        if(arr[i]>arr[i-1]+1||arr[i]==0) arr[i]=arr[i-1]+1;
        
    }    
    
    printf("%d\n",arr[n]);
    
    return 0;
}
