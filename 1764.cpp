#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[1000003][23],ans[1000003][23];

int cmp(const void *a,const void *b){
    return strcmp((const char *)a,(const char *)b);
}

int main()
{
    int i,p,n,m,cnt=0;
    scanf("%d%d",&n,&m);
    
    for(i=0;i<n+m;i++) scanf("%s",&str[i]);

    qsort(str,n+m,sizeof(str[0]),cmp);

    for(i=1;i<n+m;i++){
        if(strcmp(str[i],str[i-1])==0){
            cnt++,p=0;
            while(1){
                if(str[i][p]=='\0') break;
                ans[cnt][p]=str[i][p];
                p++;
            }
            ans[cnt][p]='\0';
        }
    }
    
    printf("%d\n",cnt);
    for(i=1;i<=cnt;i++) printf("%s\n",ans[i]);
    
    return 0;
}
