#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int dist[103][103],vis[103][103],dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
queue<edge> q;

int mx(int x,int y){ return(x>y)?x:y;}

int main(){

    int i,j,z,n,m,k,x,y,res=-1;
    
    scanf("%d%d%d",&n,&m,&k);

    for(i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        dist[x][y]=1;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(dist[i][j]==0||vis[i][j]==1) continue;
            int cnt=1;
            vis[i][j]=1;
            q.push({i,j});
            while(!q.empty()){
                edge cur=q.front(); q.pop();
                for(z=0;z<4;z++){
                    int x=cur.x+dx[z];
                    int y=cur.y+dy[z];
                    if(x<=0||y<=0||x>n||y>m) continue;
                    if(dist[x][y]==0||vis[x][y]==1) continue;
                    vis[x][y]=1;
                    cnt++;
                    q.push({x,y});
                }
            }
            res=mx(res,cnt);
        }
    }

    printf("%d\n",res);

    return 0;
}
