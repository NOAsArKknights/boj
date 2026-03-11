#include<stdio.h>

int arr[100003];

int main()
{
    int i=0,n,k,cnt=0;
    
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        if(k!=0) arr[i++]=k;
        else arr[--i]=0;
    }

    i=0;
    while(arr[i]!=0){
        cnt+=arr[i++];
    }

    printf("%d\n",cnt);
    
    return 0;
}
