/*
ID: freeman92
PROG: ATOM
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

int main(){
    ll p, n, m, k;
    cin >> p;
    //cout << p*p << endl;
    

    while(p--){

        ll ans = 0;
        cin >> n >> k >> m;
        /*
        ll total = n;
        while(total>0 && total<=m){
            ans++;
            total *= k;
        }
        if(n >= m)
            cout << 0 << endl;
        else
            cout << ans-1 << endl;
            */

        ll _m = m;
        m = m/n;
        if(n >= _m){
            cout << 0 << endl;
        }
        else{
            if(m==0){
                cout << 1 << endl;
            }
            else{
                while( m ){
                    ans++;
                    m = m/k;
                }
                cout << ans-1 << endl;
            }
        }

    }
    
	return 0;
}