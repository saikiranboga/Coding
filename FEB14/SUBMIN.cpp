/*
ID: freeman92
PROG: SUBMIN
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
int kfreq[M];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    int mx = -1;
    int mim = M+1;
    forn(i, n){
        cin >> arr[i];
        if(arr[i]>mx)
            mx = arr[i];
        if(arr[i]<mim)
            mim = arr[i];
    }
    forn(i, M)
        kfreq[i] = 0;

    int mn;
    forn(i, n){
        fore(j, i, n){
            mn = M+1;
            fori(k, i, j){
                if(arr[k]<mn)
                    mn = arr[k];
            }
            kfreq[mn]++;
        }
    }

    int q, K;
    cin >> q;
    forn(i, q){
        cin >> K;
        if(K>=mim && K<=mx)
            cout << kfreq[K] << endl;
        else cout << 0 << endl;
    }

	return 0;
}