#include <stdio.h>

int main() {
    int i,n,cnt;
    
    scanf("%d",&n);
    
    cnt=0;
    while(n--){
        int tmp=n+1;
        while(tmp%5==0){
            tmp/=5;
            cnt++;
        }
    }

    printf("%d\n",cnt);

    return 0;
}
