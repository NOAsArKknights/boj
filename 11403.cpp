#include<stdio.h>

int arr[103][103];

int main()
{
    int i,j,m,n;
    
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0) arr[i][j]=(1<<30)-1;
        }
    
    for(m=0;m<n;m++)    
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(arr[i][j]>arr[i][m]+arr[m][j]) arr[i][j]=arr[i][m]+arr[m][j];
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]!=(1<<30)-1) arr[i][j]=1;
            else arr[i][j]=0;
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) printf("%d ",arr[i][j]);
        printf("\n");
    }
    
    return 0;
}
