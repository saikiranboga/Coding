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

int main(){
    LL n,l;
    cin >> n >> l;
    LL a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);

    double mxd = 0;
    double val = 0;
    for (int i = 0; i < n-1; ++i)
    {
        val = ((double)(a[i+1]-a[i])) / 2.0;
        if(val > mxd){
            mxd = val;
        }
    }

    if( ((double)(a[0])) > mxd)
        mxd = ((double)(a[0]));
    if( ((double)(l-a[n-1])) > mxd)
        mxd = ((double)(l-a[n-1]));

    double ans = mxd;

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}