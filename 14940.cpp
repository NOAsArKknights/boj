#include<stdio.h>

int arr[1003][1003],vis[1003][1003],queue[1000003][4],posx[7]={0,1,-1,0},posy[7]={1,0,0,-1};
int f=0,r=0,n,m;

void bfs(int a,int b){
    int i;
    queue[r++][0]=a;
    queue[r++][1]=b;
    vis[a][b]=1;
    while(f<r){
        int cx=queue[f++][0];
        int cy=queue[f++][1];
        for(i=0;i<4;i++){
            if(cx+posx[i]>=0&&cy+posy[i]>=0&&arr[cx+posx[i]][cy+posy[i]]!=0){
                if(vis[cx+posx[i]][cy+posy[i]]==0||vis[cx+posx[i]][cy+posy[i]]>vis[cx][cy]+1){
                    queue[r++][0]=cx+posx[i];
                    queue[r++][1]=cy+posy[i];
                    vis[cx+posx[i]][cy+posy[i]]=vis[cx][cy]+1;
                }
            }
        }
    }
}

int main()
{
    int i,j,x,y;

    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==2) x=i,y=j;
        }
    
    bfs(x,y);
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==0) vis[i][j]++;
            printf("%d ",vis[i][j]-1);
        }
        printf("\n");
    }
    
    return 0;
}
