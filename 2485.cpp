#include <stdio.h>
#include <algorithm>

int arr[100003],arr1[100003];

int main()
{
    int i,n,k,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    std::sort(arr,arr+n);
    for(i=0;i<n-1;i++){
        arr1[i]=arr[i+1]-arr[i];
    }
    std::sort(arr1,arr1+n-1);
    for(i=0;i<n-1;i++){
        while(arr1[i+1]!=0){
            tmp=arr1[i]%arr1[i+1];
            arr1[i]=arr1[i+1];
            arr1[i+1]=tmp;
        }
        arr1[i+1]=arr1[i];
    }
    k=(arr[n-1]-arr[0])/arr1[i];
    printf("%d\n",k-n+1);
    return 0;
}
