#include<stdio.h>
int flags[1000000];
int main(){
    int t,a,b,n,i,j,k,size,indx;
    scanf("%d",&t);
    while(t--){
        for(i=0;i<1000000;i++)
            flags[i] = 1;
        scanf("%d%d%d",&a,&b,&n);
        j = 0;
        for(i=1;i<=n;i++){
            printf("%d ",j+1);
            for(k=0;k<=j;k++){
                if(flags[k]==1){
                    indx = (a*(j+1)-(b*(k+1)));
                    if(indx-1>j)
                        flags[indx-1] = 0;

                    indx = (a*(k+1)-(b*(j+1)));
                    if(indx-1>j)
                        flags[indx-1] = 0;
                }
            }
            while(flags[++j]!=1);
        }
        printf("\n");
    }
    return 0;
} 
