//Kim yun beom <1699>
#include <stdio.h>

int arr[100003];

int max(int x,int y){ return (x<=y)?x:y;}

int main()
{
    int i,j,n;
    scanf("%d",&n);

    for(i=1;i<=n;i++) arr[i]=100001;

    arr[1]=1;
    for(j=1;j<=400;j++){
        for(i=2;i<=n;i++){
            if(i-j*j>=0) arr[i]=max(arr[i],arr[i-j*j]+1);
        }
    }

    printf("%d\n",arr[n]);

    return 0;
}
