#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <fstream>
using namespace std;

#define ll long long

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define ford(i, up, bot) for(int i = (up); i > (bot); --i)
#define fordi(i, up, bot) ford(i, up, bot-1)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pt;

using namespace std;
#define mod 1000000007

//ofstream fout ("LEMOVIE.out");
//ifstream fin ("test_cases.out");

ll nCr[205][205], fnr[205][205], fact[205], sum[205];
ll n, k, n_dist;
ll a[205];
vector<ll> as;

ll ncr(ll n,ll k){
    if(k<0||n<k)
        return 0;
    if(k==0||n==k)
        return 1;

    if(nCr[n][k]!=-1)
        return nCr[n][k];

    return nCr[n][k]=(ncr(n-1,k)+ncr(n-1,k-1))%mod;
}

ll f(ll pos, ll r){
    if(r<0 || pos>=n_dist){
        //cout << "direct1 " << pos << " " << r << endl;
        return 0;
    }
    else if(n_dist-pos==1 && r==1){
        //cout << "direct2 " << pos << " " << r << endl;
        fnr[pos][r] = 1;
        return 1;
    }
    else if(n_dist-pos==1 && r!=1){
        //cout << "direct3 " << pos << " " << r << endl;
        fnr[pos][r] = 0;
        return 0;
    }
    else if(n_dist-pos<r){
        //cout << "direct4 " << pos << " " << r << endl;
        fnr[pos][r] = 0;
        return 0;
    }
    else if(n_dist-pos>0 && r<=0){
        //cout << "direct5 " << pos << " " << r << endl;
        fnr[pos][r] = 0;
        return 0;
    }
    else if(fnr[pos][r] != -1){
        //cout << "returning cached value " << pos << " " << r << " " << fnr[pos][r] << endl;
        return fnr[pos][r];
    }
    else{
        ll comb1 = ncr(sum[pos], a[ as[pos] ])%mod;
        ll comb2 = ncr(sum[pos]-1, a[ as[pos] ]-1)%mod;
        //cout << "calc for " << pos << " " << r << endl;
        fnr[pos][r] = ( ( ( (comb1-comb2)* (f(pos+1, r)%mod) )%mod) + ( ( (comb2)*(f(pos+1, r-1)%mod) )%mod) )%mod;
        //cout << "done calc for " << pos << " " << r << " " << fnr[pos][r] << " " << comb1 << " " << comb2 << endl;
        return fnr[pos][r];
    }
    assert(n<0);
    //cout << "case not found!!\n";
}

int main(){
    ll t;
    
    fact[0]=1LL;
    fori(i, 1, 200)
        fact[i]=(fact[i-1]*i)%mod;

    memset(nCr,-1,sizeof(nCr));

    cin >> t;
    while(t--){
        cin >> n;
        cin >> k;
        memset(a,0,sizeof(a));
        ll num;
        forn(i, n){
            cin >> num;
            a[num]++;
        }

        memset(fnr,-1,sizeof(fnr));

        as.clear();
        ll perm = 1;
        fori(i, 1, 200){
            if(a[i]){
                as.pb(i);
                perm = ( (perm%mod) * (fact[ a[i] ]%mod) )%mod;
            }
        }
        n_dist = as.size();
        memset(sum,0,sizeof(sum));

        sum[ n_dist-1 ] = a[as[ n_dist-1 ]];
        fordi(i, n_dist-2, 0 )
            sum[i] = sum[i+1] + a[as[i]];

        ll tmp, ans = 0;
        fori(i, 1, k){
            tmp = f(0,i);
            //cout << i << " " << tmp << endl;
            ans = (ans + tmp)%mod;
        }
        ans = ( (ans)%mod * (perm)%mod )%mod;
        if(ans < 0){
            ans = (ans+mod)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
