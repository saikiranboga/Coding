/*
ID: freeman92
PROG: TWODOGS
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

#define M 1000001
ll lft[M], rt[M];

int main(){
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    forn(i, n){
        cin >> arr[i];
    }
    forn(i, M){
        lft[i] = -1;
        rt[i] = -1;
    }

    forn(i, n){
        if(lft[ arr[i] ] == -1)
            lft[ arr[i] ] = i;
        rt[ arr[i] ] = n-1-i;
    }

    ll mn = M;

    forn(i, n){
        if( k > arr[i] && k != 2*arr[i]){
            if( lft[ k-arr[i] ] != -1){
                if( max(lft[ arr[i] ], lft[ k-arr[i] ]) < mn)
                    mn = max(lft[ arr[i] ], lft[ k-arr[i] ]);
                if( max(rt[ arr[i] ], rt[ k-arr[i] ]) < mn )
                    mn = max(rt[ arr[i] ], rt[ k-arr[i] ]);
                if( max(lft[ arr[i] ], rt[ k-arr[i] ]) < mn )
                    mn = max(lft[ arr[i] ], rt[ k-arr[i] ]);
                if( max(rt[ arr[i] ], lft[ k-arr[i] ]) < mn )
                    mn = max(rt[ arr[i] ], lft[ k-arr[i] ]);
            }
        }
    }

    if(mn != M)
        cout << mn+1 << endl;
    else
        cout <<  -1 << endl;

    return 0;
}