#include <stdio.h>
#include <algorithm>

int arr[100003],max[100003],arr1[100003];

int main()
{
    int i,j,z,t,n;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        std::sort(arr,arr+n);
        z=0;
        for(j=0;j<n;j+=2){
            arr1[z]=arr[j];
            if(z>=n-z-1) break;
            arr1[n-z-1]=arr[j+1];
            if(z>=n-z-1) break;
            z++;
        }
        for(j=0;j<n-1;j++){
            if(arr1[j]>=arr1[j+1]) max[j]=arr1[j]-arr1[j+1];
            if(arr1[j+1]>arr1[j]) max[j]=arr1[j+1]-arr1[j];
        }
        std::sort(max,max+n-1);
        printf("%d\n",max[n-2]);
    }

    return 0;
}
