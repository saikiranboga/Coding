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

    int okay[m][m];

    forn(i, m){
        okay[i][i] = 1;
        fore(j, i+1, m){
            okay[i][j] = 1;
            okay[j][i] = 1;
            forn(k, K[i]){
                if( binary_search(of[j], of[j]+K[j], of[i][k]) ){
                    okay[i][j] = 0;
                    okay[j][i] = 0;
                    break;
                }
            }
        }
    }
/*
    forn(i, m){
        forn(j, m){
            cout << okay[i][j] << " ";
        }
        cout << endl;
    }
*/
    int all = pow(2, m)-1;
    int ans = 0;
    fori(i, 0, all){
        int taken[m];
        memset(taken, 0, sizeof(taken));
        int comb = i;
        int cur = -1;
        bool take_comb = true;
        int count = 0;
        //cout << "comb: " << comb << endl;
        while(take_comb && comb){
            cur++;
            if(comb&1){
                forn(j, m){
                    if( (j!=cur) && (!okay[cur][j]) && (taken[j]) ){
                        //cout << "not okay for " << cur << " " << j << " comb: " << comb << endl;
                        take_comb = false;
                        break;
                    }
                }
                if(take_comb){
                    taken[cur] = 1;
                    count++;
                }
            }
            comb >>= 1;
        }
        if(take_comb){
            if(count>ans){
                ans = count;
            }
        }
    }

    cout << ans << endl;

    return 0;
}