#include<stdio.h>

int arr[10003];

int mx(int x,int y){ return(x>y)?x:y;}

int main(){

    int i,n,m,s=1,e=-1,res=-1;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        e=mx(e,arr[i]);
    }
    scanf("%d",&m);
    
    while(s<=e){
        int mid=(s+e)/2;
        int cnt=0;
        for(i=0;i<n;i++){
            if(mid>=arr[i]) cnt+=arr[i];
            else cnt+=mid;
        }
        if(cnt<=m){
            res=mx(res,mid);
            s=mid+1;
        }
        else e=mid-1;
    }
    
    printf("%d\n",res);
    
    return 0;
}
