#include <stdio.h>
#include <algorithm>

int arr[100003],res[100003];

int main()
{
    int n,k,i,max=-2147483647;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<k;i++){
        res[0]+=arr[i];
    }
    for(i=1;i<=n-k;i++){
        res[i]=res[i-1];
        res[i]-=arr[i-1];
        res[i]+=arr[i+k-1];
    }
    for(i=0;i<=n-k;i++){
        if(max<res[i]) max=res[i];
    }
    printf("%d\n",max);

    return 0;
}
