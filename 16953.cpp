#include<stdio.h>
#include<queue>
using namespace std;

struct edge{
    long long int x,p;
};

queue<edge> q;

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    q.push({n,1});
    while(!q.empty()){
        long long int a=q.front().x*2;
        long long int b=q.front().x*10+1;
        int par=q.front().p+1;
        q.pop();
        if(a==m||b==m){
            printf("%d",par);
            return 0;
        }
        if(a<m) q.push({a,par});
        if(b<m) q.push({b,par});
    }
    
    printf("-1");
    
    return 0;
}
