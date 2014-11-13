/*
ID: freeman92
PROG: LCPESY
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

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string A, B;
        cin >> A;
        cin >> B;
        int A_digs[10], B_digs[10];
        int A_small[26], B_small[26];
        int A_big[26], B_big[26];

        forn(i, 10){
            A_digs[i] = 0;
            B_digs[i] = 0;
        }

        forn(i, 26){
            A_small[i] = 0;
            B_small[i] = 0;
            A_big[i] = 0;
            B_big[i] = 0;
        }

        int A_sz = A.size();
        int B_sz = B.size();
        char c;
        forn(i, A_sz){
            c = A[i];
            if(c>='a' && c<='z')
                A_small[c-'a']++;
            else if(c>='A' && c<='Z')
                A_big[c-'A']++;
            else
                A_digs[c-'0']++;
        }

        forn(i, B_sz){
            c = B[i];
            if(c>='a' && c<='z')
                B_small[c-'a']++;
            else if(c>='A' && c<='Z')
                B_big[c-'A']++;
            else
                B_digs[c-'0']++;
        }

        int ans = 0;
        forn(i, 26){
            ans += min(A_small[i], B_small[i]);
            ans += min(A_big[i], B_big[i]);
        }

        forn(i, 10)
            ans += min(A_digs[i], B_digs[i]);

        cout << ans << endl;
    }
	return 0;
}