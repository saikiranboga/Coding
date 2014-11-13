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

int main() {
    ll t;
    t = 10;
    cout << t << endl;
    srand(time(NULL));
    while(t--){
        ll n, q, m;
        n = 1+rand()%6;
        q = 3;
        cout << n << " " << q << endl;
        ll a[n];
        forn(i, n){
            a[i] = -1000000000+rand()%1000000000;
            cout << a[i] << " ";
        }
        cout << endl;
        forn(i, q){
            m = 1+rand()%100;
            cout << m << endl;
        }
    }
    return 0;
}