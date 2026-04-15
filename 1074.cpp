#include<stdio.h>

int abc(int n,int r,int c){
    if(n==1) return 0;
    
    int half=n/2;
    int size=half*half;

    if(r<half&&c<half) return abc(n/2,r,c);
    if(r>=half&&c<half) return size+abc(n/2,r-half,c);
    if(r<half&&c>=half) return 2*size+abc(n/2,r,c-half);
    return 3*size+abc(n/2,r-half,c-half);
}

int main()
{
    int n,r,c;
    
    scanf("%d%d%d",&n,&r,&c);
    
    printf("%d\n",abc(1<<n,c,r));

    return 0;
}
