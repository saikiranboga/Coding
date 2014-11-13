/*
ID: freeman92
PROG: SEASORT2
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
#define Max 10010
typedef pair<int, int> pt;

int n;
int a[Max];

vector<pt> solve(int a[]){
    vector<pt> p;
    forn(i, n)
        p.pb(mp(a[i],i));

    vector<pt> ans;
    forn(i, n){
        pt me(p[i].F,p[i].S);
        
        fore(j, i+1, n){
            if(p[j].F<me.F)
                me.F = p[j].F, me.S = p[j].S;
        }
        if(me.S != i){
            ans.pb(mp(i,me.S));
            reverse(&p[i], &p[me.S+1]);
            fore(j, i+1, n)
                p[j].S = j;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    forn(i, n)
        cin >> a[i];
    vector<pt> ans0;
    ans0 = solve(a);
    int sz0 = ans0.size();
    cout << sz0 << endl;
    forn(i, sz0)
        cout << ans0[i].F+1 << " " << ans0[i].S+1 << endl;
	return 0;
}