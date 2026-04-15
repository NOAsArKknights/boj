#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int dist[503][503],vis[503][503],dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
queue<edge> q;

int mn(int x,int y){ return(x<y)?x:y;}

int main(){

    int i,j,n,m,r,c;
    
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&c);
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(r==i&&c==j) continue;
            dist[i][j]=1000000;
        }
    }
    
    vis[r][c]=1;
    q.push({r,c});
    while(!q.empty()){
        edge cur=q.front(); q.pop();
        for(i=0;i<8;i++){
            int x=cur.x+dx[i];
            int y=cur.y+dy[i];
            if(x<=0||y<=0||x>n||y>n) continue;
            if(vis[x][y]==1) continue;
            dist[x][y]=mn(dist[x][y],dist[cur.x][cur.y]+1);
            vis[x][y]=1;
            q.push({x,y});
        }
    }
    
    for(i=0;i<m;i++){
        scanf("%d%d",&r,&c);
        printf("%d\n",dist[r][c]);
    }
    
    return 0;
}
