#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[1003][1003],queue[1003],vis[1003];
int f=0,r=0;

void dfs(int s,int n){
    int i;
    queue[r++]=s;
    if(!vis[s]) vis[s]=s;
    while(f<r){
        int c=queue[f++];
        for(i=1;i<=n;i++){
            if(arr[c][i]==1&&!vis[i]){
                queue[r++]=i;
                vis[i]=s;
            }
        }
    }
}

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;    
    return *x-*y;
}

int main()
{
    int i,n,m,x,y,cnt=0;
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        arr[x][y]=arr[y][x]=1;
    }
    
    for(i=1;i<=n;i++) dfs(i,n);
    qsort(vis,n+1,sizeof(int),cmp);
        
    for(i=0;i<n;i++){
        if(vis[i]!=vis[i+1]) cnt++;
    }
    printf("%d\n",cnt);
    
    return 0;
}
