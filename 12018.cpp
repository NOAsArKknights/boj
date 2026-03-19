#include<stdio.h>
#include<stdlib.h>

int arr[103],tmp[103];

int cmp1(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;

    return *x-*y;
}

int cmp2(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;

    return *y-*x;
}

int main(){

    int i,j,n,m,p,l,cnt=0;

    scanf("%d%d",&n,&m);
    
    for(i=0;i<n;i++){
        scanf("%d%d",&p,&l);
        for(j=0;j<p;j++) scanf("%d",&arr[j]);
        if(p<l) tmp[i]=1;
        else{
            qsort(arr,p,sizeof(int),cmp2);
            tmp[i]=arr[l-1];
        }
    }
    qsort(tmp,n,sizeof(int),cmp1);
    for(i=0;i<n;i++){
        if(cnt+tmp[i]>m){
            printf("%d\n",i);
            return 0;
        }
        cnt+=tmp[i];
    }

    printf("%d\n",n);

    return 0;
}
