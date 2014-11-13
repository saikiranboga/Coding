/*
ID: freeman92
PROG: BIT
LANG: C++
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
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

int bitCount(int u){
     int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

int main(){
    int t, n;
    cin >> t;
    
    int ones[1001];

    memset(ones, 0, 1001);

    forn(i, 1001)
        ones[i] = bitCount(i);

    fore(i, 1, 1001)
        ones[i] += ones[i-1];

    while(t--){
        cin >> n;
        cout << ones[n] << endl;
    }
	return 0;
}