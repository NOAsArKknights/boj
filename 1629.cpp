#include<stdio.h>

long long int tmp;
int a,b,c;

long long int abc(long long int n){
    if(n==1) return a;
    if(n%2==0){
        tmp=(abc(n/2))%c;
        tmp*=tmp;
        tmp%=c;
        return tmp;
    }
    else{
        tmp=(abc(n/2))%c;
        tmp*=tmp;
        tmp%=c;
        tmp*=a;
        tmp%=c;
        return tmp;
    }
}

int main()
{
    int i;

    scanf("%d%d%d",&a,&b,&c);

    a%=c;
    printf("%lld\n",abc(b));

    return 0;
}
