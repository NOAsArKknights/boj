#include<stdio.h>
#include<queue>
using namespace std;

struct EDGE{
    int x,y,v;
};

queue<EDGE> q;
char str[103][103];
int arr[103][103],vis[103][103],px[5]={-1,0,1,0},py[5]={0,1,0,-1};

int main()
{
    int i,j,n,m;
    
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++){
        scanf(" %s",&str[i]);
        for(j=0;j<m;j++) arr[i][j]=str[i][j]-48;
    }

    q.push({0,0,1});
    vis[0][0]=1;
    while(!q.empty()){
        for(i=0;i<4;i++){
            int xx=q.front().x+px[i];   
            int yy=q.front().y+py[i];   
            if(xx<0||xx>=n||yy<0||yy>=m||vis[xx][yy]||!arr[xx][yy]) continue;
            q.push({xx,yy,q.front().v+1});
            vis[xx][yy]=q.front().v+1;
        }
        q.pop();
    }
    
    printf("%d\n",vis[n-1][m-1]);
    
    return 0;
}
