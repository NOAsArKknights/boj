#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int arr[53][53],dist[53][53],dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,-1,-1,-1,0,1,1,1};
queue<edge> q;

int mx(int x,int y){ return(x>y)?x:y;}

int main(){

    int i,j,z,n,m,max=-1;
    
    scanf("%d%d",&n,&m);
    
    memset(dist,-1,sizeof(dist));    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==0) continue;
            q.push({i,j});
            dist[i][j]=0;
        }
    }
    
    while(!q.empty()){
        edge cur=q.front(); q.pop();
        for(z=0;z<8;z++){
            int x=cur.x+dx[z];
            int y=cur.y+dy[z];
            if(x<0||y<0||x>=n||y>=m) continue;
            if(dist[x][y]!=-1) continue;
            dist[x][y]=dist[cur.x][cur.y]+1;
            max=mx(max,dist[x][y]);
            q.push({x,y});
        }
    }
    
    printf("%d\n",max);
    
    return 0;
}
