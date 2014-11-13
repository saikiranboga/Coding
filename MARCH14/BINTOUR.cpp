
/*
ID: freeman92
PROG: BINTOUR
LANG: C++
*/
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
#include <stdint.h>
#include <unistd.h>
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

#define MOD 1000000009
#define Max 600000
ll power[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
ll fact[Max];
int main(){
    ios_base::sync_with_stdio(false);
    ll k;
    cin >> k;
    ll n = power[k];
    fact[0] = 1;
    fori(i, 1, n)
        fact[i] = (fact[i-1]*i)%MOD;
    ll ans[n+1];
    fori(i, 0, n/2-1)
        ans[i] = 0;

    ll mul = ((n/2)*(n/2))%MOD;
    mul = (mul*2)%MOD;

    ans[n] = fact[n];
    ans[n-1] = (fact[n-2]*mul)%MOD;

    ll bin=1, r=1;
    fordi(i, n-2, n/2){
        bin = (bin*( (n/2)-r))%MOD;
        ans[i] = ( ((fact[i-1]*mul)%MOD)*bin)%MOD;
        r++;
    }
    fori(i, 1, n){
        cout << ans[i] << endl;
    }
    return 0;
}