#include<stdio.h>

int arr[100003],queue[100003],vis[100003];
int f=0,r=0;

void dfs(int s,int n){
    int i;
    queue[r++]=s;
    vis[s]=1;
    while(f<r){
        int c=queue[f++];
        if(c>0&&(vis[c-1]>vis[c]+1||vis[c-1]==0)){
            queue[r++]=c-1;
            vis[c-1]=vis[c]+1;
        }
        if(c<=99999&&(vis[c+1]>vis[c]+1||vis[c+1]==0)){
            queue[r++]=c+1;
            vis[c+1]=vis[c]+1;
        }
        if(c*2<=100000&&(vis[c*2]>vis[c]+1||vis[c*2]==0)){
            queue[r++]=c*2;
            vis[c*2]=vis[c]+1;
        }
    }
}

int main()
{
    int i,n,k;
    
    scanf("%d%d",&n,&k);

    dfs(n,k);

    printf("%d\n",vis[k]-1);
    
    return 0;
}
