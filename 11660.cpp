#include<stdio.h>

int arr[1030][1030],inp[1030][1030];

int main()
{
    int i,j,n,m,x1,x2,y1,y2;
    
    scanf("%d%d",&n,&m);
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
            inp[i][j]=arr[i][j];
        }
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            arr[i][j]+=arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
    
    while(m--){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]);
    }    

    return 0;
}
