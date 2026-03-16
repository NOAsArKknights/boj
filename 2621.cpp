#include <stdio.h>
#include <algorithm>

int num[8],cnt[8],res[12],print[10];
char arr[8];

int main()
{
    int i,z=0,t=0,r=0,l=0,e3,e2,e1,e2_2,g=0,non=0,max=0;
    for(i=0;i<5;i++){
        scanf("%s %d",&arr[i],&num[i]);
        if(arr[i]=='R') cnt[0]++;
        if(arr[i]=='B') cnt[1]++;
        if(arr[i]=='Y') cnt[2]++;
        if(arr[i]=='G') cnt[3]++;
    }
    std::sort(num,num+5);
    for(i=0;i<4;i++){
        if(num[i]+1==num[i+1]) t++;
    }
    for(i=0;i<5;i++){
         res[num[i]]++;
    }
    for(i=0;i<10;i++){
        if(res[i]==4){
            r=4;
            e1=i;
        }
        if(res[i]==3){
            e3=i;
            r=3;
            if(l==1) l=3;
        }
        if(res[i]==2){
            if(l==0) e2=i;
            if(l==1){
                e2_2=i;
                l=2;
            }
            if(l!=2) l=1;
            if(r==3) l=3;
        }
    }
    if(e2>e2_2) g=1;
    else g=2;
    if(cnt[0]==5||cnt[1]==5||cnt[2]==5||cnt[3]==5){
        if(t!=4) print[z]=600+num[4];
        non++;
        z++;
    }
    if(t==4){
        if(cnt[0]==5||cnt[1]==5||cnt[2]==5||cnt[3]==5) print[z]=900+num[4];
        else print[z]=500+num[4];
        non++;
        z++;
    }
    if(r==4){
        print[z]=800+e1;
        non++;
        z++;
    }
    if(r==3&&l==0){
        print[z]=400+e3;
        non++;
        z++;
    }
    if(r==3&&l==3){
        print[z]=e3*10+e2+700;
        non++;
        z++;
    }
    if(l==2){
        if(g==1) print[z]=e2*10+300+e2_2;
        if(g==2) print[z]=e2_2*10+300+e2;
        non++;
        z++;
    }
    if(l==1){
        print[z]=200+e2;
        non++;
        z++;
    }
    if(non==0){
        print[z]=100+num[4];
        z++;
    }
    for(i=0;i<z;i++){
        if(max<print[i]){
            max=print[i];
        }
    }
    printf("%d\n",max);
    return 0;
}
