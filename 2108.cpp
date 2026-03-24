#include<stdio.h>
#include<stdlib.h>

int arr[500003],man[8003];

int cmp(const void *a,const void *b){
    return *(const int *)a-*(const int *)b;
}

int main()
{
    int i,n,r=0,max,ind;
    double cnt=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        man[arr[i]+4000]++;
    }

    qsort(arr,n,sizeof(int),cmp);
    
    for(i=0;i<n;i++) cnt+=arr[i];
    if(cnt/n> -1&&cnt/n<0) printf("0\n");
    else printf("%.0lf\n",cnt/n);
    printf("%d\n",arr[n/2]);
    max=0;
    for(i=0;i<=8000;i++){
        if(man[i]>max){
            max=man[i];
            ind=i;
        }
    }
    for(i=0;i<=8000;i++){
        if(man[i]==max&&r<2){
            r++;
            ind=i;
        }
    }
    printf("%d\n",ind-4000);
    printf("%d\n",arr[n-1]-arr[0]);
    
    return 0;
}
