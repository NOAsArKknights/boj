#include<stdio.h>

int arr[10],vis[10],n,m;

void bt(int x){
    if(x==m){
        for(int i=0;i<m;i++) printf("%d ",arr[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){    
            vis[i]=1;
            arr[x]=i;
            bt(x+1);
            vis[i]=0;
        }
    }
}

int main(){

    scanf("%d%d",&n,&m);

    bt(0);

    return 0;
}
