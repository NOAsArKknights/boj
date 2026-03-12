#include <stdio.h>

int arr[13];

int main(){
    
    int i,n,k,cnt=0;
    
    scanf("%d%d",&n,&k);

    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=n-1;i>=0;i--){
        if(arr[i]<=k){
            cnt+=k/arr[i];
            k%=arr[i];
        }
    }

    printf("%d\n",cnt);

    return 0;
}
