#include<stdio.h>

int arr[10003];
char str[10];

void push(int a){
    int i=0;
    while(arr[i]!=0){
        i++;
    }
    arr[i]=a;
}

void pop(){
    int i=0;
    while(arr[i]!=0){
        i++;
    }
    if(i!=0){
        printf("%d\n",arr[i-1]);
        arr[i-1]=0;
    }
    else printf("-1\n");
}

void size(){
    int i=0;
    while(arr[i]!=0){
        i++;
    }
    printf("%d\n",i);
}

void empty(){
    if(arr[0]==0) printf("1\n");
    else printf("0\n");
}

void top(){
    int i=0;
    while(arr[i]!=0){
        i++;
    }
    if(i!=0){
        printf("%d\n",arr[i-1]);
    }
    else printf("-1\n");
}

int main()
{    
    int i,n,a;
    
    scanf("%d",&n);
    
    while(n--){
        
        scanf("%s",&str);
        if(str[0]=='p'&&str[1]=='u'){
            scanf("%d",&a);
            push(a);
        }
        if(str[0]=='p'&&str[1]=='o') pop();
        if(str[0]=='s'&&str[1]=='i') size();
        if(str[0]=='e'&&str[1]=='m') empty();
        if(str[0]=='t'&&str[1]=='o') top();
    }
    
    return 0;
}
