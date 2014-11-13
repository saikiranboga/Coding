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

#define modo 1000000009

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
    ll t;
    cin >> t;
    while(t--){
        ll n, q, m;
        cin >> n >> q;
        ll a[n];
        forn(i, n)
            cin >> a[i];
        while(q--){
            cin >> m;          
            ll modN[m];
            
            forn(i, m)
                modN[i]=0;
            ll p = pw(n);
            ll ans = 0;
            forn(i,p+1){
                ll sum = 0;
                int cur = 0;
                ll tmp = i;
                while(tmp>0){
                    if(tmp&1){
                        sum += a[cur];
                    }
                    tmp >>= 1;
                    cur++;
                }
                if(abs(sum)%m == 0){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}