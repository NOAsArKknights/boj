#include<stdio.h>

int arr[5][5],vis[13],dist[13],r[5],l[5],n[5],cnt=100;

int ans(int x,int y){ return(x>y)?x-y:y-x;}

bool check(int h){
    int x=h/3,y=h%3;
    if(x==2&&l[y]!=15) return false;
    if(y==2&&r[x]!=15) return false;
    if(h==6&&n[1]!=15) return false;
    if(h==8&&n[0]!=15) return false;
    return true;
}

void bt(int h){
    if(h==9){
        int cost=0;
        for(int i=0;i<9;i++){
            int x=i/3,y=i%3;
            cost+=ans(arr[x][y],dist[i]);
        }
        cnt=(cnt>cost)?cost:cnt;
        return;
    }
    for(int i=1;i<10;i++){
        if(vis[i]==0){
            int x=h/3,y=h%3;;
            dist[h]=i;
            vis[i]=1;
            r[x]+=i,l[y]+=i;
            if(x==y) n[0]+=i;
            if(x+y==2) n[1]+=i;
            if(check(h)) bt(h+1);
            vis[i]=0;
            r[x]-=i,l[y]-=i;
            if(x==y) n[0]-=i;
            if(x+y==2) n[1]-=i;        
        }
    }
}

int main(){

    int i,j;
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    bt(0);

    printf("%d\n",cnt);

    return 0;
}
