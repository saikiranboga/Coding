#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <fstream>
using namespace std;
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define pii pair<int ,int >
#define NL puts("")
#define II ({ int a; scanf("%d",&a); a;})
#define IL ({ int64 a; scanf("%lld",&a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define ICA(n) ({ char a[n]; scanf("%s",&a);  a;})
#define OC printf("Case %d:",cs);

ofstream fout ("LEMOVIE_AC_others.out");
ifstream fin ("test_cases.out");

template <class T, class U> inline T max (T &a, U &b)
{
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b)
{
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
int n,k,len;
vector<int >V;
int64 fact[202];
int64 dp[202][202][202][2],m[202];
int64 call(int pos,int ex,int val,bool prev){
    if(ex > k)
        return 0;
    if(val == len) {
        return fact[n - pos];
    }
    int64 &ret = dp[pos][ex][val][prev];
    if(ret != -1)
        return ret;
    ret = 0;
    if(pos < m[V[val-1]] && prev)
        ret = (call(pos+1,ex,val,true)*(m[V[val-1]] - pos))%mod;
    if(val < len){
        ret = (ret + call(pos+1,ex+1,val+1,true)*(m[V[val]]-m[V[val-1]]))%mod;
        if(val < len-1)ret = (ret + call(pos,ex,val+1,false))%mod;
    }
    return ret;
}

int main() {
    fact[0] = 1;
    For(i,200) fact[i] = (fact[i-1]*i)%mod;
    int t;
    fin >> t;
    For(cs,t){
        memo(m,0);
        memo(dp,-1);
        fin >> n >> k;
        V.pb(0);
        rep(i,n){
            int x;
            fin >> x;
            m[x]++;
            if(m[x] == 1) V.pb(x);
        }
        sort(all(V));
        For(i,201) m[i] += m[i-1];
        len = V.size();
        int64 ans = call(0,0,1,0) ;
        fout << ans << endl;
        V.clear();
    }
}