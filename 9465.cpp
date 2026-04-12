#include<stdio.h>

int arr[100003][5];

int abc(int a,int b,int c){
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int main()
{
    int i,t,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&arr[i][1]);
        for(i=1;i<=n;i++) scanf("%d",&arr[i][2]);
        for(i=2;i<=n;i++){
            arr[i][1]+=abc(arr[i-2][1],arr[i-2][2],arr[i-1][2]);
            arr[i][2]+=abc(arr[i-2][2],arr[i-2][1],arr[i-1][1]);
        }
        if(arr[n][1]<arr[n][2]) printf("%d\n",arr[n][2]);
        else printf("%d\n",arr[n][1]);
    }

    return 0;
}
