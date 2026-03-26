#include <stdio.h>
#include <algorithm>

int arr1[8],arr2[8],res[8][8];

int main()
{
    int i,j,z,n,tmp,g;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            scanf("%d:%d",&arr1[j],&arr2[j]);
            g=arr1[j];
            if(arr1[j]>12) g-=12;
            if((g*60+arr2[j])>=arr2[j]*12) res[j][0]=(g*60+arr2[j])-arr2[j]*12;
            else res[j][0]=arr2[j]*12-(g*60+arr2[j]);
            res[j][1]=j;
            while(7200<=res[j][0]) res[j][0]-=720;
            if(res[j][0]>360) res[j][0]=720-res[j][0];
        }
        for(j=0;j<5;j++){
            for(z=0;z<5;z++){
                if(res[j][0]<res[z][0]){
                    tmp=res[j][0];
                    res[j][0]=res[z][0];
                    res[z][0]=tmp;
                    tmp=res[j][1];
                    res[j][1]=res[z][1];
                    res[z][1]=tmp;
                }
                if(res[j][0]==res[z][0]&&j!=z){
                    if(arr1[res[j][1]]<arr1[res[z][1]]){
                        tmp=res[j][0];
                        res[j][0]=res[z][0];
                        res[z][0]=tmp;
                        tmp=res[j][1];
                        res[j][1]=res[z][1];
                        res[z][1]=tmp;
                    }
                    else if(arr1[res[j][1]]>arr1[res[z][1]]){
                        continue;
                    }
                    else{
                        if(arr2[res[j][1]]<arr2[res[z][1]]){
                            tmp=res[j][0];
                            res[j][0]=res[z][0];
                            res[z][0]=tmp;
                            tmp=res[j][1];
                            res[j][1]=res[z][1];
                            res[z][1]=tmp;
                        }
                        else if(arr2[res[j][1]]>arr2[res[z][1]]){
                            continue;
                        }
                    }
                }
            }
        }
        if(10>arr1[res[2][1]]) printf("0");
        printf("%d:",arr1[res[2][1]]);
        if(10>arr2[res[2][1]]) printf("0");
        printf("%d\n",arr2[res[2][1]]);
    }

    return 0;
}
