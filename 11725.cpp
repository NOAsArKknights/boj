#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

vector<int> arr[100003];
int vis[100003],par[100003];

int main()
{
    int i,n,x,y;
    
    scanf("%d",&n);

    for(i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1]=1;
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(i=0;i<arr[cur].size();i++){
            int tmp=arr[cur][i];
            if(!vis[tmp]){
                vis[tmp]=1;
                par[tmp]=cur;
                q.push(tmp);
            }
        }
    }
    
    for(i=2;i<=n;i++) printf("%d\n",par[i]);

    return 0;
}
