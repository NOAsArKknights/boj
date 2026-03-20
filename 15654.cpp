#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[10],inp[10],vis[10];
int n,m;

int cmp(const void *a,const void *b){
    return *(const int *)a-*(const int *)b;
}

void dfs(int depth){
    int i,j;
    if(depth==m){
        for(i=0;i<m;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(vis[i]==0){
            arr[depth]=inp[i];
            vis[i]=1;
            dfs(depth+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int i;
    
    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++) scanf("%d",&inp[i]);
    
    qsort(inp,n,sizeof(int),cmp);

    dfs(0);
    
    return 0;
}
