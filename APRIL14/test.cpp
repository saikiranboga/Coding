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
#define ll long long
typedef pair<int, int> pt;

#define Max 2000000

ll muls[Max];

int main(){
  ios_base::sync_with_stdio(false);
  /*
  ll count;
  fori(n, 1, 1000){
    count = 0;
    fore(i, 1, n)
      count += (n-1)/i;
    cout << count << endl;
  }

  memset(muls, 0, sizeof(muls));
  forn(i, Max)
    muls[i] = 1;

  fori(i, 2, Max/2){
    int cur = i;
    while(cur<Max){
      muls[cur]++;
      cur += i;
    }
  }

  forn(i, Max)
    cout << muls[i] << endl;
*/
    int t,n;
    cin >> t;
    while(t--){
      cin >> n;
      cout << n << ", ";
    }
	return 0;
}