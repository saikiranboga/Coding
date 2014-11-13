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

bool comp(int a, int b){
    return a > b;
}

int B[1001][1001], C[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    int t,n,m,k;
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        vector<int> gains;

        int ar[n+1];
        ar[0] = 0;
        fori(i, 1, n)
            cin >> ar[i];

        fori(i, 1, n)
            fori(j, 1, m)
                cin >> B[i][j];
        fori(i, 1, n)
            fori(j, 1, m)
                cin >> C[i][j];

        int ans = 0;
        fori(cell, 1, n){
            int val = B[cell][ ar[cell] ];
            ans += val;
            int gn = 0;
            fori(color, 1, m)
                if(  B[cell][color]-val-C[cell][color] > gn)
                    gn = B[cell][color]-val-C[cell][color];
            gains.pb(gn);
        }

        sort(gains.begin(), gains.end(), comp);

        int sz = gains.size();
        
        if(k >= sz){
            forn(i, sz)
                ans += gains[i];
        }
        else{
            forn(i, k)
                ans += gains[i];
        }

        cout << ans << endl;
    }
    return 0;
}

/*
5 3 3
3 3 2 1 2
2 1 3
1 2 2
1 4 6
0 3 1
6 0 5
1 0 0
1 2 0
1 0 4
0 0 2
0 0 1

5 3 3
3 3 2 2 1
2 1 3
1 2 2
1 4 6
0 3 1
6 0 5
1 0 0
1 2 0
1 0 4
0 0 2
0 0 1

5 3 3
2 2 1 1 3
2 1 3
1 2 2
1 4 6
0 3 1
6 0 5
1 0 0
1 2 0
1 0 4
0 0 2
0 0 1

1 3 3
2
6 0 5
0 0 2

*/