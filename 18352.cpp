#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct edge{
    int u,v;
    
    bool operator<(const edge& o) const{
        return v>o.v;
    }
};

priority_queue<edge> pq;
vector<int> v[300003];
int dist[300003];

int main(){
    
    int i,n,m,k,x,a,b;
    
    scanf("%d%d%d%d",&n,&m,&k,&x);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
    }
    for(i=1;i<=n;i++) dist[i]=1e9;
    dist[x]=0;
    pq.push({x,0});
    while(!pq.empty()){
        edge cur=pq.top(); pq.pop();
        if(cur.v>dist[cur.u]) continue;
        for(i=0;i<v[cur.u].size();i++){
            int nxt=v[cur.u][i];
            if(dist[nxt]>dist[cur.u]+1){
                dist[nxt]=dist[cur.u]+1;
                pq.push({nxt,dist[nxt]});
            }
        }
    }

    bool bl=false;
    for(i=1;i<=n;i++){
        if(dist[i]==k){
            printf("%d\n",i);
            bl=true;
        }
    }

    if(!bl) printf("-1\n"); 

    return 0;
}
