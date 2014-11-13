#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
#include<map>
#include<queue>
#include<bitset>
using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
const double pi = acos(-1.0);
typedef long long Int;

const int N = 100009;
char c[N+1];
int cnt[N+1];
int tlen[N+1];

void solve(string s) {
  int n;
  char chr = s[0];
  int count, idx = 0;
  int s_length = s.length();
  FOR(i,1,s_length){
    count = 1;
    while(i < s_length && s[i] == chr){
      i++;
      count++;
    }
    c[idx] = chr;
    cnt[idx] = count;
    idx++;
    if(i < s_length){
      chr = s[i];
    }
  }
  Int total=0;
  n = idx+1;
  FOR(i,0,n-1) {
    //    cin>>c[i]>>cnt[i];
    total += cnt[i]*1LL*(cnt[i]+1)/2;
    tlen[i]=(i==0?cnt[i]:cnt[i]+tlen[i-1]);
  }

  vector<int> d1 (n);
  int l=0, r=-1;
  for (int i=0; i<n; ++i) {
    int k = (i>r ? 0 : min (d1[l+r-i], r-i));
    while (i+k < n && i-k >= 0 && mp(c[i+k], cnt[i+k])==mp(c[i-k], cnt[i-k]))  ++k;
    d1[i] = k--;
    if (i+k > r)
      l = i-k,  r = i+k;
  }


  FOR(i,0,n-1) {
    int cur = d1[i];
    int add = tlen[i-1] - (i-cur<0?0:tlen[i-cur]);
    if(i-cur>=0 && i+cur<n && c[i-cur]==c[i+cur]) add+=min(cnt[i-cur], cnt[i+cur]);
    total+=add;
  }

  cout<<total<<endl;
}


int main()
{
  string s;
  cin >> s;
  solve(s);
}  
