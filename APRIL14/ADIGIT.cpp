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

int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    string inp;
    cin >> inp;
    int sz = inp.size();
    int digits[sz];
    
    int num;
    forn(i, sz){
      num = (int)(inp[i]-'0');
      digits[i] = num;
    }
    int freq[sz+1][10];
    memset(freq, 0, sizeof(freq));
    fori(i,1,sz){
      forn(j,10)
        freq[i][j] = freq[i-1][j];
      freq[i][digits[i-1]]++;
    }
/*
    forn(i,sz){
      forn(j,10)
        cout << freq[i][j] << " ";
      cout << endl;
    }
*/
    int idx;
    while(m--){
      cin >> idx;
      idx--;
      ll ans = 0;
      int val = digits[idx];
      forn(j,10){
        if(j<val)
          ans += ((val-j)*freq[idx][j]);
        else
          ans += ((j-val)*freq[idx][j]);
      }
      cout << ans << endl;
    }
	return 0;
}