#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int dist[53][53],vis[53][53],dx[8]={-1,1,0,0,-1,-1,1,1},dy[8]={0,0,-1,1,-1,1,-1,1};
queue<edge> q;

int main(){
    
    int i,j,k,w,h;
    
    while(1){
        scanf("%d%d",&w,&h);
        if(w==0&&h==0) break;
        
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                scanf("%d",&dist[i][j]);
            }
        }
        
        int cnt=0;
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                if(dist[i][j]==0||vis[i][j]==1) continue;
                q.push({i,j});
                vis[i][j]=1;
                cnt++;
                while(!q.empty()){
                    edge cur=q.front(); q.pop();
                    for(k=0;k<8;k++){
                        int x=cur.x+dx[k];
                        int y=cur.y+dy[k];
                        if(x<0||y<0||x>=h||y>=w) continue;
                        if(vis[x][y]==1||dist[x][y]==0) continue;
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                vis[i][j]=0;
            }
        }
        
        printf("%d\n",cnt);
    }
    
    return 0;
}
