#include<stdio.h>

int arr[1000003];

int main()
{
    int i,j,tmp,n,m;

    scanf("%d%d",&n,&m);
    for(i=2;i<=m;i++){
        j=1,tmp=i;
        while(tmp*j<=m){
            arr[tmp*j]++;
            j++;
        }
    }

    for(i=n;i<=m;i++){
        if(arr[i]==1) printf("%d\n",i);
    }

    return 0;
}
