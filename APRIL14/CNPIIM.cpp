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
#include <cassert>
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
#define ll long long
typedef pair<int, int> pt;

#define Max 10000000

ll muls[Max];
ll les[Max];

int main(){
  ios_base::sync_with_stdio(false);
  memset(muls, 0, sizeof(muls));
  forn(i, Max)
    muls[i] = 1;

  muls[0] = 0;

  fori(i, 2, Max/2){
    int cur = i;
    while(cur<Max){
      muls[cur]++;
      cur += i;
    }
  }

  les[0] = 0;
  les[1] = 0;
  fori(i, 2, Max)
    les[i] = les[i-1] + muls[i-1];

  int t,n,prod;
  cin >> t;
  while(t--){
    cin >> n;
    assert(n<=2500);
    ll ans = 0;
    fori(i, 1, (n-1)/2){
      prod = i*(n-i);
      ans += les[prod];
    }
    ans = ans*2;
    if(n%2!=1){
      prod = (n/2)*(n/2);
      ans += les[prod];
    }
    cout << ans << endl;
  }

	return 0;
}