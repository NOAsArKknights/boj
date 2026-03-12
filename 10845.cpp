#include<stdio.h>

int arr[30003],r=0;
char str[10];

void push(int a){
    int i=r;
    while(1){
        if(arr[i]==0){
            arr[i]=a;
            break;
        }
        i++;
    }
}

void pop(){
    if(arr[r]!=0) printf("%d\n",arr[r]);
    else printf("-1\n");
    arr[r++]=0;
}

void size(){
    int i=r;
    while(1){
        if(arr[i]==0) break;
        i++;
    }
    printf("%d\n",i-r);
}

void empty(){
    int i=r;
    while(1){
        if(arr[i]==0) break;
        i++;
    }
    if(i==r) printf("1\n");
    else printf("0\n");
}

void fro(){
    if(arr[r]!=0) printf("%d\n",arr[r]);
    else printf("-1\n");
}

void back(){
    int i=r;
    while(1){
        if(arr[i]==0) break;
        i++;
    }
    if(i!=r) printf("%d\n",arr[i-1]);
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
        if(str[0]=='f'&&str[1]=='r') fro();
        if(str[0]=='b'&&str[1]=='a') back();                
    }
    
    return 0;
}
