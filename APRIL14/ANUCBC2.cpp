#include <cstdio>
#define moduo 1000000009
#define ll long long
using namespace std;

ll test,t,n,q,i,a[100008],u,m,dp[100008][108]={0},j,mod,num,x[108],y[108],modN[108],poz,k,s;
char c;
bool neg;

ll pw(ll n){
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    ll ret = pw(n/2);
    ret = (ret*ret)%moduo;
    if(n&1)
        ret = (ret*2)%moduo;
    return ret;
}

int main() {
    scanf("%lld",&test);
    dp[0][0]=1;
    for (t=0; t<test; t++) {
        scanf("%lld %lld",&n,&q);
        for (i=1; i<=n; i++) scanf("%lld",&a[i]);
        for (u=0; u<q; u++) {
            scanf("%lld",&m);
            
            if(m==1){
                ll ans = pw(n);
                printf("%lld\n",ans);
                continue;
            }

            for (i=0; i<m; i++) modN[i]=0;
            
            for (i=1; i<=n; i++) {
                mod=a[i]%m;
                if(mod<0)
                    mod = (mod+m)%m;
                modN[mod]++;
            }
            for (i=0; i<m; i++) {
                for (j=1; j<m; j++) dp[i][j]=0;
                dp[i][0]=1;
                s=0;
                for (j=1; j<=modN[i]; j++) {
                    s += i;
                    if(s>m) s-=m;
                    dp[i][s]++;
                }
            }
            
            /*
            for(i=0;i<m;i++){
                for(j=0;j<m;j++){
                    printf("%d ", dp[i][j]);
                }
                printf("\n");
            }
            */

            for (i=0; i<m; i++) x[i]=dp[0][i];

            for (i=1; i<m; i++) {
                for (j=0; j<m; j++) y[j]=0;
                for (j=0; j<m; j++) {
                    for (k=0; k<m; k++) {
                        poz=j-k;
                        if (poz<0) poz+=m;
                        y[j]+=x[k]*dp[i][poz];
                    }
                }
                for (j=0; j<m; j++) x[j]=y[j];
            }
            printf("%lld\n",x[0]%moduo);
            //for (i=0; i<m; i++) dp[0][i]=0;
            //dp[0][0]=1;
            /*
            for (i=1; i<=n; i++) {
                x=mod[i];
                for (j=0; j<m; j++) {
                    dp[i][x]=dp[i-1][x]+dp[i-1][j];
                    if (dp[i][x]>=moduo) dp[i][x]-=moduo;
                    x++;
                    if (x>=m) x-=m;
                }
            }
            printf("%d\n",dp[n][0]);
            */
        }
    }

    return 0;
}
