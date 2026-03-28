#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int inp[13],arr[13],m,n,res[13],vis[13];

int cmp(const void *a,const void *b){
    return *(const int *)a-*(const int *)b;
}

void abc(int len){
    int i,tmp[10003]={0,};
    if(m==len){
        for(i=0;i<m;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
    else{
        for(i=0;i<n;i++){
            if(!vis[i]&&!tmp[inp[i]]){
                res[len]=inp[i];
                vis[i]=1;
                tmp[inp[i]]=1;
                abc(len+1);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    int i,k,p=0;
    
    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++) scanf("%d",&inp[i]);

    qsort(inp,n,sizeof(int),cmp);
    
    abc(0);
           
    return 0;
}
