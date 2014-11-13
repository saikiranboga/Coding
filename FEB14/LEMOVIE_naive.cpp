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
#define mod 100000007
ll nCr[205][205], fnr[205][205], fact[205], sum[205];
ll n, k, n_dist;
ll a[205];
ll oe[205];


void check(ll a[]){
    ll oelem = 1;
    ll mx = a[0];
    fore(i, 1, n){
        if(a[i] > mx){
            oelem++;
            mx = a[i];
        }
    }
    oe[oelem]++;
}

int main(){
    cin >> n;
    cin >> k;

    memset( fact, 0, sizeof(fact) );
    fact[0]=1LL;
    fori(i, 1, 200)
        fact[i] = fact[i-1]*i;

    ll freq[205];
    memset( freq, 0 , sizeof(freq) );
    memset( a, 0, sizeof(a) );
    forn(i, n){
        cin >> a[i];
        freq[ a[i] ]++;
    }
    ll perm = 1;
    forn(i, 201){
        if(freq[i]){
            perm *= fact[ freq[i] ];
        }
    }
    sort(a, a+n);
    ll ans = 0;
    memset(oe, 0, sizeof(oe));
    do{
        check(a);
    }while(next_permutation(a, a+n));

    fori(i, 1, k){
        ans += oe[i];
        //cout << i << " " << oe[i] << endl;
    }
    cout << ans*perm << endl;
    return 0;
}
