#include <stdio.h>
#include <string.h>
#include <math.h>

#define ll long long

#define fore(i, l, r) for(i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)

#define modo 1000000009

ll C(ll n,ll r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    ll ans = 1;
    int i;

    for(i = 1; i <= r; i++){
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

ll pw(ll n){
    if(n==0)
        return 1;
    if(n==1)
        return 2;
    ll ret = pw(n/2);
    ret = (ret*ret)%modo;
    if(n&1)
        ret = (ret*2)%modo;
    return ret;
}


int main() {
    ll t,tc, i, j, r;
    scanf("%lld",&tc);
    while(tc--){
        ll n, q, m;
        scanf("%lld",&n);
        scanf("%lld",&q);
        ll a[n];
        forn(i, n)
            scanf("%lld",&a[i]);
        while(q--){
            scanf("%lld",&m);    
            ll modN[m];
            
            forn(i, m)
                modN[i]=0;

            ll mod;
            forn(i, n){
                mod = a[i]%m;
                if(mod<0)
                    mod = (mod+m)%m;
                modN[mod]++;
            }
            ll cmb, add[m][m+1];

            memset(add, 0, sizeof(add));

            forn(r, m){
                if(r==0){
                    add[r][0] = pw(modN[r]);
                    continue;
                }
                forn(t,modN[r]+1){
                    cmb = C(modN[r],t);
                    add[r][(r*t)%m] += cmb;
                }
            }
            ll dp[m+1][m+1];
            memset(dp, 0, sizeof(dp));
            dp[0][0] = 1;
            forn(i,m){
                fori(j,0,m){
                    forn(r,m){
                        dp[i+1][j] = ( dp[i+1][j] + (dp[i][(j-r+m)%m]*add[i][r])%modo )%modo;
                    }
                }
            }
            printf("%lld\n",dp[m][m]%modo);
        }
    }
    return 0;
}