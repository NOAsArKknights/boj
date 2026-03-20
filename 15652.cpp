#include<stdio.h>

int arr[10];
int n,m;

void dfs(int s,int depth){
    int i;
    if(depth==m){
        for(i=0;i<m;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(i=s;i<=n;i++){
        arr[depth]=i;
        dfs(i,depth+1);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    
    dfs(1,0);
    
    return 0;
}
