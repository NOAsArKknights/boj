#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr1[100003],arr2[100003],r;

int cmp(const void *a,const void *b){
    const int *x=(const int *)a;
    const int *y=(const int *)b;
    
    if(*x>*y) return 1;
    else if(*x<*y) return -1;
    else return 0;
}

void by(int s,int e,int a){
    if(s>=e){
        r=0;
        return;
    }
    if(arr1[(s+e)/2]>a) by(s,(s+e)/2,a);
    else if(arr1[(s+e)/2]<a) by(1+(s+e)/2,e,a);
    else{
        r=1;
        return;
    }
}

int main()
{
    int i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr1[i]);
        
    qsort(arr1,n,sizeof(int),cmp);

    scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%d",&arr2[i]);
    
    for(i=0;i<m;i++){
        by(0,n,arr2[i]);
        printf("%d\n",r);
    }
    
    return 0;
}
