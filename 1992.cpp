#include<stdio.h>

int arr[70][70];
char buf[70];

void abc(int sx,int sy,int ex,int ey){
    int r=2;
    for(int i=sx;i<ex;i++){
        for(int j=sy;j<ey;j++){
            if(i==sx&&j==sy&&arr[i][j]==1) r=1;
            else if(i==sx&&j==sy&&arr[i][j]==0) r=0;
            else if(r==1&&arr[i][j]==0) r=2;
            else if(r==0&&arr[i][j]==1) r=2;
        }
    }
    if(r==1){
        printf("1");
        return;
    }
    else if(r==0){
        printf("0");
        return;
    }
    else{
        printf("(");
        abc(sx,sy,sx+(ex-sx)/2,sy+(ey-sy)/2);
        abc(sx,sy+(ey-sy)/2,sx+(ex-sx)/2,ey);        
        abc(sx+(ex-sx)/2,sy,ex,sy+(ey-sy)/2);
        abc(sx+(ex-sx)/2,sy+(ey-sy)/2,ex,ey);
        printf(")");
    }
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%s",buf);
        for(j=0;j<n;j++){
            arr[i][j]=buf[j]-'0';
        }
    }
    
    abc(0,0,n,n);
        
    return 0;
}
//1100101001010001
