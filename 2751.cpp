#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000003];

int compare(const void *a,const void *b){
    int x = *(int *)a;
    int y = *(int *)b;
    
    if(x>y) return 1;
    else if(x<y) return -1;
    else return 0;
}

int main(){
    
    int i,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++) scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(int),compare);

    for(i=0;i<n;i++) printf("%d\n",arr[i]);
    
    return 0;
}
