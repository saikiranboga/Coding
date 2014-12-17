#include <bits/stdc++.h>
using namespace std;

#define LL long long int

#define inf 1000000000
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define VI vector<int>
#define PII pair<LL, LL>
#define all(v) (v.begin(), v.end())

#define MX 200010

int main(){
    int n, m;
    cin >> n;
    vector< PII > throws;
    LL d;
    for (int i = 0; i < n; ++i){
        cin >> d;
        throws.pb( mp(d,0) );
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> d;
        throws.pb( mp(d,1) );
    }
    sort(throws.begin(), throws.end());
    int c1 = 0 , c2 = 0;
    LL a, b;
    LL mxd = -1000000000LL;
    LL mxa = -1000000000LL;
    LL mxb = -1000000000LL;
    int ind = 0;
    do{
        // cout << c1 << "<-->" << c2 << endl;
        a = c1*2 + (n-c1)*3;
        b = c2*2 + (m-c2)*3;
        // cout << a-b << ",," << mxd << endl;
        if(a-b > mxd){
            mxd = a-b;
            mxa = a;
            mxb = b;
        }
        else if(a-b == mxd){
            if(a > mxa){
                mxa = a;
                mxb = b;
            }
        }
        if(throws[ind].ss==0)
            c1++;
        else
            c2++;
        ind++;
    }while(ind <= n+m);
    cout << mxa << ":" << mxb << endl;
    return 0;
}