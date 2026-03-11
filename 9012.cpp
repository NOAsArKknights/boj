#include<stdio.h>

char str[53];

int main()
{
    int i,n,cnt,r,p;
    char c;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf("%s",&str);
        p=0,cnt=0,r=1;
        while(str[p]!=0){
            if(str[p]=='(') cnt++;
            else cnt--;
            if(cnt<0) r=0; 
            p++;
        }
        if(cnt==0&&r==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
