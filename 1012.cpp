#include<stdio.h>

int arr[53][53],vis[53][53],posx[5]={-1,0,1,0},posy[5]={0,-1,0,1},r;

void abc(int x,int y){
    for(int z=0;z<4;z++){
        if(arr[x+posx[z]][y+posy[z]]==1&&!vis[x+posx[z]][y+posy[z]]){
            vis[x+posx[z]][y+posy[z]]=1;
            abc(x+posx[z],y+posy[z]);
        }
    }
}

int main()
{
    int i,j,z,t,m,n,k,x,y;

    scanf("%d",&t);

    while(t--){
        r=0;
        scanf("%d%d%d",&m,&n,&k);
        for(i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            arr[x+1][y+1]=1;
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(arr[i][j]==1&&!vis[i][j]){
                    abc(i,j);
                    r++;
                }
            }
        }
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                arr[i][j]=vis[i][j]=0;
            }
        }
        printf("%d\n",r);    
    }
    
    return 0;
}
