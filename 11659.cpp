#include<stdio.h>

int arr[100003];

int main()
{
    int i,n,m,c,p,q;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++){
        scanf("%d",&c);
        arr[i]=arr[i-1]+c;
    }

    while(m--){
        scanf("%d%d",&p,&q);
        printf("%d\n",arr[q]-arr[p-1]);
    }

    return 0;
}
