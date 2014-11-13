#include<stdio.h>
#define c2(x) (((x)*(x-1))>>1)
 
int main(){
    int t,n;
        int i,j,k,val;
        long long tot,c,ctr,b;
        int arr[100001];
        scanf("%d",&t);
        while(t--){
                ctr = 0;
        tot = 0;
                scanf("%d",&n);
                for(i=0;i<n;i++){
                        scanf("%d",&arr[i]);
                }
                //nC2^2
                c = c2(n);
        b = (n+1)*(n+3)*(n+8)/6;
                tot = c*c - b;
 
                for(i=0;i<n;i++){
                        for(j=i;j<n;j++){
                                val = 1;
                                for(k = 1;j+k<n; k++){
                                        val = (arr[i+k]-arr[i+k-1] == arr[j+k]-arr[j+k-1]);
                                        if(val)ctr++;
                                        else break;
 
                                }
                        }
 
                }
                tot += ctr; 
                printf("%lld\n",tot);
 
        }
 
        return 0;
}
