/*
ID: freeman92
PROG: SEARRAYS
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
#define MOD 1000000007
#define M 100010
ll power(int n){
    if(n==0)
        return 1;
    else if(n==1)
        return 2;
    else{
        ll ret = power(n/2);
        ret = ( (ret%MOD)*(ret%MOD))%MOD;
        if(n&1){
            ret = (ret*2)%MOD;
        }
        return ret;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int dp[n+1];
        dp[0] = 1;
        fori(i, 1, n){
            if(i>=k)
                dp[i] = (dp[i-1] + dp[i-k])%MOD;
            else
                dp[i] = dp[i-1];
        }
        cout << dp[n] << endl;
    }
	return 0;
}