#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define bitcount __builtin_popcount
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define rz(x) resize(n)
#define cl()  clear()
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%llu",&x)
using namespace std;


vector < vector <int> > s;
vector < pair <int, int> > res;

bool kuhn (int v, vector <bool> &used, vector <int> &pair)
{
    if (used[v]) {
        return false;
    }
    int i;
    used[v] = true;
    for (i = 0; i < s[v].size(); i++) {
        int to = s[v][i];
        if (pair[to] == -1 || kuhn (pair[to], used, pair)) {
            pair[to] = v;
            return true;
        }
    }
    return false;
}

void check (int n, int k)
{
    vector <int> pair (k, -1);
    vector <bool> used (n, false);
    res.clear();
    int i;

    for (i = 0; i < n; i++) {
        fill (used.begin(), used.end(), false);
        kuhn (i, used, pair);
    }
    int sum=0;

    for (i = 0; i < k; i++) {
        if (pair[i] != -1) {
            res.push_back (make_pair (pair[i], i));
            sum++;
        }
    }
    if (sum == n) {
        printf ("YES\n");
    } else {
        printf ("NO\n");
    }
    return;
    cout << sum  << endl;
}
int main()
{
    int t;
    S (t);

    while (t--) {
        int n,m;
        s.clear();
        S (n);
        S (m);
        s.resize (n);

        int chk[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                chk[i][j] = 0;

        while (m--) {
            int x,y;
            S (x);
            S (y);
            x--;
            y--;
            if(chk[x][y] != 1){
                chk[x][y] = 1;
                chk[y][x] = 1;
                s[x].pb (y);
                s[y].pb (x);
            }
        }
        if(n%2 != 0)
            cout << "NO\n";
        else
            check (n, n);
    }
    return 0;
}