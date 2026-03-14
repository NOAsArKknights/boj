#include<stdio.h>

char str[53][53];
int check[53][53],arr[53][53];

int main()
{
    int i,j,m,n,r=0,x,y,cnt,p,min=65;
    
    scanf("%d%d",&n,&m);

    arr[0][0]=p=1;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(!(i==0&&j==0)){
                arr[i][j]=p*-1;
                p*=-1;
            }
        }
        p*=-1;
    }
    
    for(i=0;i<n;i++){
        scanf("%s",&str[i]);
        for(j=0;j<m;j++){
            if(str[i][j]=='W') check[i][j]=1;
            else check[i][j]=-1;
        }
    }
    
    for(i=0;i<n;i++){
        if(i+8>n) break;
        for(j=0;j<m;j++){
            if(j+8>m) break;
            cnt=0,p=1;
            for(x=i;x<i+8;x++){
                for(y=j;y<j+8;y++){
                    if(check[x][y]!=p*arr[x-i][y-j]) cnt++;
                }
            }
            if(min>cnt) min=cnt;
            cnt=0,p=-1;
            for(x=i;x<i+8;x++){
                for(y=j;y<j+8;y++){
                    if(check[x][y]!=p*arr[x-i][y-j]) cnt++;
                }
            }
            if(min>cnt) min=cnt;
        }
    }
    
    printf("%d\n",min);
    
    return 0;
}
