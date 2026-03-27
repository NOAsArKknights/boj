#include<stdio.h>

int arr[1003],res[1003];

int main()
{
    int i,j,n,max;

    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=0;i<n;i++){
        max=-1;
        for(j=0;j<i;j++){
            if(arr[i]>arr[j]&&max<res[j]) max=res[j];
        }
        res[i]=max+1;
    }
    
    max=-1;
    for(i=0;i<n;i++) if(max<res[i]) max=res[i];
    printf("%d\n",max+1);
    
    return 0;
}
