#include<stdio.h>

int arr[10003],n;

int mx(int x,int y){ return(x>y)?x:y;}

int by(long long m){
    int cnt=0;
    for(int i=0;i<n;i++) cnt+=arr[i]/m;
    return cnt;
}

int main(){
    
    int i,k,res=1000001;
    long long cnt=0,min=0,max=-1;
    
    scanf("%d%d",&n,&k);
    
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        max=mx(arr[i],max);
    }
    
    while(min<=max){
        long long m=(min+max)/2;
        if(m==0) m=1;
        int cur=by(m);
        if(cur>=k){
            min=m+1;
            res=cur;
            cnt=m;
        }
        else max=m-1;
    }
    
    printf("%lld\n",cnt);
    
    return 0;
}
