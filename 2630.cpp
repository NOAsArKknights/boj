#include<stdio.h>

int arr[150][150],i,j,bcnt=0,wcnt=0;

void abc(int sx,int nx,int sy,int ny){
    int b,w;
    b=0,w=0;
    for(i=sx;i<nx;i++){
        for(j=sy;j<ny;j++){
            if(arr[i][j]==1) w=1;
            else b=1;
        }
    }
    if(w==1&&b==0){
        wcnt++;
        return;    
    }
    else if(w==0&&b==1){
        bcnt++;
        return;
    }
    if(nx-sx==1){
        return;
    }
    else{
        abc(sx,sx+(nx-sx)/2,sy,sy+(ny-sy)/2);
        abc(sx,sx+(nx-sx)/2,sy+(ny-sy)/2,ny);
        abc(sx+(nx-sx)/2,nx,sy,sy+(ny-sy)/2);
        abc(sx+(nx-sx)/2,nx,sy+(ny-sy)/2,ny);
    }
}

int main()
{
    int n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    
    abc(0,n,0,n);
    
    printf("%d\n%d\n",bcnt,wcnt);
    
    return 0;
}
