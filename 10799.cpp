#include<stdio.h>
#include<string.h>

char str[100003];
int arr[100003];

int main(){

    int i,len,l=0,cnt=0;
    
    scanf(" %s",&str);

    len=strlen(str);

    for(i=0;i<len;i++){
        if(str[i]=='('){
            l++;
        }
        else{
            l--;
            if(str[i-1]=='(') cnt+=l;
            else cnt++;
        }
    }

    printf("%d\n",cnt);

    return 0;
}
