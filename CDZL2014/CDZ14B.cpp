#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
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

int maze[1000][1000];
int done[1000][1000];
int n, m;
int cal(int x, int y, int cur, int steps){
    if(x==n-1 && y==m-1)
        return steps+1;
    steps++;
    done[x][y] = 1;
    int mn = 2000000;
    //if(x-1>=0 && !done[x-1][y] && maze[x-1][y]==1-cur){
    //    mn = min(mn, cal(x-1, y, 1-cur, steps) );
    //}
    if(x+1<n && !done[x+1][y] && maze[x+1][y]==1-cur){
        mn = min(mn, cal(x+1, y, 1-cur, steps) );
    }
    //if(y-1>=0&& !done[x][y-1] && maze[x][y-1]==1-cur){
//        mn = min(mn, cal(x, y-1, 1-cur, steps) );
    //}
    if(y+1<m && !done[x][y+1] && maze[x][y+1]==1-cur){
        mn = min(mn, cal(x, y+1, 1-cur, steps) );
    }
    done[x][y] = 0;
    if(mn != 2000000){
        steps = mn;
        return steps;
    }
    else{
        return 20000000;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        string s;
        forn(i, n){
            cin >> s;
            forn(j, m)
                maze[i][j] = s[j]-'0';
        }
        memset(done, 0, sizeof(done) );
        int ans = cal(0,0,maze[0][0],0);
        if(ans > 1000000)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
	return 0;
}