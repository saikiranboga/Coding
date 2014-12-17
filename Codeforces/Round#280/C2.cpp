#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<int, int>
#define all(v) (v.begin(), v.end())

#define MX 1000010

//..

bool comp(PII a, PII b){
    if(a.ss == b.ss)
        return a.ff < b.ff;
    return a.ss < b.ss;
}

int main(){
    LL n, r, avg;
    cin >> n >> r >> avg;
    PII ar[n];
    LL tot = 0;
    for (int i = 0; i < n; ++i){
        cin >> ar[i].ff >> ar[i].ss;
        tot += ar[i].ff;
    }
    sort(ar, ar+n, comp);
    LL cur_tot = tot;
    LL req_tot = avg*n;
    LL need = max(0LL, req_tot - cur_tot);
    int i = 0;
    LL essays = 0;
    while(need){
        LL posb = min(need,r-ar[i].ff);
        need -= posb;
        essays += posb*ar[i].ss;
        i++;
    }
    cout << essays << endl;
    return 0;
}