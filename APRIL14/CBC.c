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

ll pwr(ll bs, ll p){
    if(p==0)
        return 1;
    if(p==1)
        return bs;
    ll ret = pwr(bs, p/2);
    ret = (ret*ret)%modo;
    if(p&1)
        ret = (ret*bs)%modo;
    return ret;
}

//#define gc getchar_unlocked
#define gc getchar

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=gc();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=gc();
    }
}

int main() {
    int t,tc, i, j, r,k;
    //scanf("%d",&tc);
    fastRead(&tc);
    ll inv_val[100001];
    inv_val[0] = 0;
    inv_val[1] = 1;
    fori(i, 2, 100000)
        inv_val[i] = pwr(i,modo-2)%modo;
    while(tc--){
        int n, q, m;
        //scanf("%d",&n);
        //scanf("%d",&q);
        fastRead(&n);
        fastRead(&q);
        ll a[n];
        int tmp;
        forn(i, n){
            fastRead(&tmp);
            a[i] = tmp;
            //scanf("%lld",&a[i]);
        }
        while(q--){
            //scanf("%d",&m);
            fastRead(&m);
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
            ll cmb, sum[m];

            memset(sum, 0, sizeof(sum));

            ll nc;

            forn(r,m){
                nc = modN[r];
                cmb = 1;
                fori(k,0,nc){
                    sum[(r*k)%m] += cmb;
                    cmb = ( ((cmb*(nc-k))%modo)*(inv_val[k+1]) )%modo;
                }
            }

            forn(r,m)
                printf("%lld ",sum[r]);
            printf("\n\n");

            ll dp[m][m];
            memset(dp, 0, sizeof(dp));

            dp[0][0] = pw(modN[0]);
            fori(j,1,m-1)
                dp[0][j] = 0;

            fori(i,1,m-1){
                forn(j,m){
                    forn(r,m){
                        if((j-r+m)%m>=0)
                            dp[i][j] = (dp[i][j] + (dp[i-1][(j-r+m)%m]*sum[r])%modo )%modo;
                    }
                }
            }

            forn(i,m){
                forn(j,m)
                    printf("%lld ",dp[i][j]);
                printf("\n");
            }

            printf("%lld\n",dp[m-1][m-1]%modo);
        }
    }
    return 0;
}