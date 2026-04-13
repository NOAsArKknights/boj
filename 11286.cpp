#include<stdio.h>

int arr[100003];
int size=0;

int cha(int x,int y){
    if(x<0&&y<0) return (x<y)?0:1;
    if(x>0&&y>0) return (x<y)?1:0; 
    if(x>0&&y<0) return (x<y*(-1))?1:0; 
    if(x<0&&y>0) return (x*(-1)<=y)?1:0; 
}

void push(int x){
    int i=++size;
    while(i!=1&&cha(x,arr[i/2])){
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
        if(c<size&&cha(arr[c+1],arr[c])) c++;
        if(cha(arr[c],tmp)){
            arr[p]=arr[c];
            p=c;
            c*=2;
        }
        else break;
    }
    arr[p]=tmp;
    return ret;
}

int main()
{
    int i,n,k;
    scanf("%d",&n);
    
    while(n--){
        scanf("%d",&k);
        if(k==0){
            if(size==0) printf("0\n");
            else printf("%d\n",pop());
        }
        else push(k);
    }
    
    return 0;
}
