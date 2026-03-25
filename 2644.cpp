#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[103];
int vis[103];
queue<int> q;

int main()
{
    int i,gx,gy,x,y,m,n,r=2;
    
    scanf("%d%d%d%d",&n,&gx,&gy,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    q.push(gy);
    vis[gy]=1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(i=0;i<arr[cur].size();i++){
            int tmp=arr[cur][i];
            if(!vis[tmp]){
                if(tmp==gx){
                    r=1;
                }
                vis[tmp]=vis[cur]+1;
                q.push(tmp);
            }
        }
        if(r==1) break;
    }

    if(r==1) printf("%d\n",vis[gx]-1);
    else printf("-1\n");
    
    return 0;
}
