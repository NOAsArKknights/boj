#include <stdio.h>

int arr[100003];
int size=0;

void push(int x){
    int i=++size;
    while(i!=1&&x<arr[i/2]){
        arr[i]=arr[i/2];
        i/=2;
    }    
    arr[i]=x;
}

int pop(){
    int ret=arr[1];
    int tmp=arr[size--];
    int p=1,c=2;
    while(c<=size){
        if(c<size&&arr[c]>arr[c+1]) c++;
        if(tmp<=arr[c]) break;
        arr[p]=arr[c];
        p=c;
        c*=2;
    }
    arr[p]=tmp;
    return ret;
}

int main(){
    int i,n,k;
    
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        if(k==0){
            if(size!=0) printf("%d\n",pop());
            else printf("0\n");
        }
        else push(k);
    }

    return 0;
}
