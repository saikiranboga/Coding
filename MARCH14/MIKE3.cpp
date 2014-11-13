/*
ID: freeman92
PROG: MIKE3
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

#define Max 20010

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int K[m];
    int of[m][Max];
    vector< vector<int> > g(m);
    forn(i, m){
        cin >> K[i];
        forn(j, K[i]){
            cin >> of[i][j];
        }
    }

    forn(i, m){
        fore(j, i+1, m){
            forn(k, K[i]){
                if( binary_search(of[j], of[j]+K[j], of[i][k]) ){
                    g[i].pb(j);
                    g[j].pb(i);
                    break;
                }
            }
        }
    }

    vector<pt> ins;
    forn(i, m)
        ins.pb( mp(g[i].size(), i) );
    sort(ins.begin(), ins.end());

    int ans = 0;
    int used[m];
    memset(used, 0, sizeof(used));
    forn(i, m){
        if(used[ ins[i].S ]==0){
            ans++;
            used[ ins[i].S ] = 1;
            int cur = ins[i].S;
            int sz = g[cur].size();
            forn(j, sz){
                used[ g[cur][j] ] = 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}