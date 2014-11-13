/*
ID: freeman92
PROG: ORPROFIT
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
#include <stdio.h>
#include <stdlib.h>
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

#define MOD 1000000007
#define Mx 1010

vector<int> graph[Mx];
int colVals[Mx];
int visited[Mx];
int n, m;
int ans = 0;
void dfs(int v){
    visited[v] = 1;
    ans = ans|colVals[v];
    int sz = graph[v].size();
    forn(i, sz){
        if(!visited[ graph[v][i] ])
            dfs( graph[v][i] );
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    vector<pt> ints;
    cin >> n;
    forn(i, n){
      cin >> colVals[i];
    }
    int x, y;
    string s;
    forn(i, n){
        cin >> s;
        int sz = s.size();
        forn(j, sz){
          if(s[j]=='Y' && i<j){
            graph[i].pb(j);
            graph[j].pb(i);
          }
        }
    }
    
    memset(visited, 0, sizeof(visited));

    dfs(0);
    cout << ans << endl;
	return 0;
}