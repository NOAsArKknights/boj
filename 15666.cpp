#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int inp[13],arr[13],m,n;

int cmp(const void *a,const void *b){
    return *(const int *)a-*(const int *)b;
}

void dfs(int depth){
    int i,vis[10003]={0,};
    if(depth==m){
        for(i=0;i<m;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }    
    else{
        for(i=0;i<n;i++){
            if(!vis[inp[i]]&&arr[depth-1]<=inp[i]){
               arr[depth]=inp[i];
               vis[inp[i]]=1;
               dfs(depth+1);
            }
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
