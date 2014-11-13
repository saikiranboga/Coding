#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define DEBUG if(0)
#define PAUSE system("pause")
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define LAST(a) (int(a.size()) - 1)
#define PN(n)   printf("%d",n)
#define PDN(n)  printf("%lf",n)
#define PLN(n)  printf("%lld",n)
#define PS(n)   printf("%s",n)
#define PL()    printf("\n")
#define SN(n)   scanf("%d",&n)
#define SDN(n)  scanf("%lf",&n)
#define SLN(n)  scanf("%lld",&n)
#define SS(n)   scanf("%s",n)
#define i64 long long
#define ff first
#define ss second

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1E-9;
//const int INF = 100000000;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535897932384626433832795;
const int MAX = 150;
int dx[]={ 0, 0, -1, 1, -1, 1,-1, 1};
int dy[]={-1, 1,  0, 0, -1,-1, 1, 1};


string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

int countPalindrome(int k, string s) {

  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;

  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i;

    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;


    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }


  set<int>st;
  for (int i = 1; i < n-1; i++) {
    if (P[i] == k ) {
      st.insert((i - 1 - P[i])/2);
    }
  }
  delete[] P;

  return st.size();
}

int main()
{
  int k;
  string s;
  cin >> s;
  int s_length = s.length();

  int ans = 0;
  for (int i=1;i<=s_length;i++)
    ans = ans + countPalindrome(i,s);
  cout << ans << endl;
  return 0;
}
