#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int dist[203][203],vis[203][203],dx[6]={-2,-2,0,0,2,2},dy[6]={-1,1,-2,2,-1,1};
queue<edge> q;

int mn(int x,int y){ return(x<y)?x:y;}

int main(){

    int i,j,n,r1,c1,r2,c2;
    
    scanf("%d",&n);
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(r1==i&&c1==j) continue;
            dist[i][j]=1000000;
        }
    }
    
    vis[r1][c1]=1;
    q.push({r1,c1});
    while(!q.empty()){
        edge cur=q.front(); q.pop();
        for(i=0;i<6;i++){
            int x=cur.x+dx[i];
            int y=cur.y+dy[i];
            if(x<0||y<0||x>=n||y>=n) continue;
            if(vis[x][y]==1) continue;
            dist[x][y]=mn(dist[x][y],dist[cur.x][cur.y]+1);
            vis[x][y]=1;
            q.push({x,y});
        }
    }
    
    if(dist[r2][c2]==1000000) printf("-1\n");
    else printf("%d\n",dist[r2][c2]);

    return 0;
}
