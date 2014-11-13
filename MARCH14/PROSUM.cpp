/*
ID: freeman92
PROG: WALK
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
#include <string>
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

int main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        ll rem = 0, num2s = 0;
        ll ones_0s = 0;
        forn(i, n){
            cin >> a[i];
            if(a[i]==0 || a[i]==1){
                rem += (n-1-ones_0s);
                ones_0s++;
            }
            else if(a[i]==2){
                num2s++;
            }
        }
        ll ans = ( (n*(n-1))/2 ) - (rem) - ( (num2s*(num2s-1))/2 );
        cout << ans << endl;
    }
	return 0;
}