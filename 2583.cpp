#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int x,y;
};

int res[10003],dist[103][103],vis[103][103],dx[5]={-1,1,0,0},dy[5]={0,0,1,-1};
queue<edge> q;

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;
    return *x-*y; 
}

int main(){

    int i,j,z,n,m,k,sx,ex,sy,ey,p=0;
    
    scanf("%d%d%d",&n,&m,&k);

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            dist[i][j]=1;
        }
    }

    for(i=0;i<k;i++){
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        for(j=sx;j<ex;j++){
            for(z=sy;z<ey;z++){
                dist[z][j]=-1;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(dist[i][j]==-1||vis[i][j]==1) continue;
            q.push({i,j});
            vis[i][j]=1;
            int cnt=1;
            while(!q.empty()){
                edge cur=q.front(); q.pop();
                for(z=0;z<4;z++){
                    int x=cur.x+dx[z];
                    int y=cur.y+dy[z];
                    if(x<0||y<0||x>=n||y>=m) continue;
                    if(dist[x][y]==-1||vis[x][y]==1) continue;
                    vis[x][y]=1;
                    cnt++;
                    q.push({x,y});
                }
            }
            res[p]=cnt;
            p++;
        }
    }

    qsort(res,p,sizeof(int),cmp);
    
    printf("%d\n",p);
    for(i=0;i<p;i++) printf("%d ",res[i]);    
    
    return 0;
}
