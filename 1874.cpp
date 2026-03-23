#include<stdio.h>

int arr[100003],top=-1;
char res[200002];

void push(int x){
    arr[++top]=x;
}
void pop(){
    top--;
}

int abc(){
    return arr[top];
}

int main()
{
    int i,n,m,p=1,idx=0;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&m);
        while(p<=m){
            push(p++);
    
            res[idx++]='+';
        }
        if(abc()==m){
            pop();
            res[idx++]='-';
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
    
    for(i=0;i<idx;i++) printf("%c\n",res[i]);

    return 0;
}
