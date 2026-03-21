#include<stdio.h>

int arr[1003][1003],n,vis[1003],queue[3003];
int front=0, rear=0;

void dfs(int x){
    int i;
    vis[x]=1;
    printf("%d ",x);
    for(i=1;i<=n;i++){
        if(arr[x][i]==1&&!vis[i]){
            dfs(i);
        }
    }
}

void bfs(int s,int n){
    int i;
    queue[rear++]=s;
    vis[s]=1;
    while(front<rear){
        int c = queue[front++];
        printf("%d ",c);
        for(i=1;i<=n;i++){
            if(arr[c][i]==1&&!vis[i]){
                queue[rear++]=i;
                vis[i]=1;
            }
        }
    }
    
}

int main()
{
    int i,m,v,x,y;
    
    scanf("%d%d%d",&n,&m,&v);
    
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        arr[x][y]=arr[y][x]=1;
    }
    
    dfs(v);
    printf("\n");    
    for(i=0;i<=n;i++) vis[i]=0;
    bfs(v,n);    
    
    return 0;
}
