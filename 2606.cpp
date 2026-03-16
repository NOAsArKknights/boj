#include<stdio.h>

int arr[103][103],n,cnt[103],v[103][103];

void dfs(int x,int y){
    int i;
    for(i=1;i<=n;i++){
        if(arr[x][i]==1&&v[x][i]==0){
            cnt[x]++,cnt[i]++;
            v[x][i]=v[i][x]=1;
            dfs(i,x);
        }
    }
}

int main()
{
    int i,m,p,q,tmp=0;
    
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&p,&q);
        arr[p][q]=arr[q][p]=1;
    }

    dfs(1,1);

    for(i=2;i<=n;i++){
        if(cnt[i]>0) tmp++;
    }

    printf("%d\n",tmp);

    return 0;
}
