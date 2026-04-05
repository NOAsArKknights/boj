//Kim yun beom <1495>
#include <stdio.h>

int v[103],D[103][1003];

int max(int x,int y){ return (x>y)?x:y;}

int main()
{
    int i,j,n,s,m,cnt=0,r=0;
    scanf("%d%d%d",&n,&s,&m);

    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            D[i][j]=-1;

    for(i=1;i<=n;i++)
        scanf("%d",&v[i]);

    D[0][s]=s;
    for(i=0;i<n;i++){
        for(j=0;j<=m;j++)
            if(D[i][j]!=-1){
                if(j+v[i+1]<=m)
                    D[i+1][j+v[i+1]]=max(D[i+1][j+v[i+1]],D[i][j]+v[i+1]);
                if(j-v[i+1]>=0)
                    D[i+1][j-v[i+1]]=max(D[i+1][j-v[i+1]],D[i][j]-v[i+1]);
            }
        for(j=1;j<=m;j++)
            cnt=max(cnt,D[i][j]);
        if(cnt==-1){
            r=1;
            break;
        }
    }

    cnt=-1;
    for(i=0;i<=m;i++)
        cnt=max(cnt,D[n][i]);

    if(cnt==-1) r=1;

    if(r==1) printf("-1\n");
    else printf("%d\n",cnt);

    return 0;
}
/*
3 5 10
5 3 7
*/
