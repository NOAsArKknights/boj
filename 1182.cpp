#include<stdio.h>

int arr[23],n,res=0,s;

void bt(int x,int sum){
    if(x==n){
        if(sum==s) res++;
        return;
    }
    bt(x+1,sum+arr[x]);
    bt(x+1,sum);
}

int main(){
    
    int i;

    scanf("%d%d",&n,&s);

    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    
    bt(0,0);
    
    if(s==0) res--;
    printf("%d\n",res);
    
    return 0;
}
