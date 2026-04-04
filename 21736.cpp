#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

char str[603],dist[603][603];
int vis[603][603],dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
queue<edge> q;

int mx(int x,int y){ return(x>y)?x:y;}

int main(){
    
    int i,j,n,m,cnt=0;
    
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        scanf(" %s",str);
        for(j=0;j<m;j++){
            dist[i][j]=str[j];
            if(dist[i][j]=='I'){
                q.push({i,j});
                vis[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        edge cur=q.front(); q.pop();
        for(i=0;i<4;i++){
            int x=cur.x+dx[i];
            int y=cur.y+dy[i];
            if(x<0||y<0||x>=n||y>=m) continue;
            if(dist[x][y]=='X'||vis[x][y]==1) continue;
            vis[x][y]=1;
            if(dist[x][y]=='P') cnt++;
            q.push({x,y});
        }
    }

    if(cnt==0) printf("TT\n");
    else printf("%d\n",cnt);
    
    return 0;
}
