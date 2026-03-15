#include<stdio.h>
#include<queue>
using namespace std;

int imp[13];

int main()
{
    int i,t,n,m,k,a;
    
    scanf("%d",&t);
    while(t--){
        queue<vector<int>> q,p;
        a=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&k);
            q.push({i,k});
            imp[k]++;
        }
        while(1){
            if(a==n) break;
            for(i=9;i>0;i--){
                if(imp[i]>0) break;
            }
            while(1){
                vector<int> cur=q.front();
                if(i==cur[1]) break;
                q.push({cur[0],cur[1]});
                q.pop();
            }
            p.push(q.front());
            q.pop();
            imp[i]--;
            a++;
        }
        for(i=0;i<n;i++){
            vector<int> cur=p.front();
            if(cur[0]==m) printf("%d\n",i+1);
            p.pop();
        }
        for(i=1;i<10;i++) imp[i]=0;
    }
    
    return 0;
}
