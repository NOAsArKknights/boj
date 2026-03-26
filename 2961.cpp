#include<stdio.h>

int sin[13],sen[13];

int abc(int s,int b){
    return (s>b)?s-b:b-s;
}

int main(){

    int i,j,n,min=1000000001;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d%d",&sin[i],&sen[i]);

    for(i=1;i<(1<<n);i++){
        int s=1,b=0;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                s*=sin[j];
                b+=sen[j];
            }
        }
        if(min>abc(s,b)) min=abc(s,b);
    }

    printf("%d\n",min);

    return 0;
}
