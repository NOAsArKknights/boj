#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
vector<pair<int,int>> v[1003];

int arr[1003];

int main()
{
    int i,n,m,s,e,x,y,val;

    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&val);
        v[x].push_back({y,val});
    }
    scanf("%d%d",&s,&e);
    
    for(i=1;i<=n;i++) arr[i]=(1<<31)-1;
    
    arr[s]=0;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first;
        int c=pq.top().second;
        pq.pop();
        
        if(arr[c]<d) continue;
    
        for(i=0;i<v[c].size();i++){
            int tmp=v[c][i].first;
            int cost=v[c][i].second;
            if(arr[tmp]>cost+d){
                arr[tmp]=cost+d;
                pq.push({cost+d,tmp});
            }
        }
    }
    
    printf("%d\n",arr[e]);
    
    return 0;
}
