#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;
typedef long long int ll;

#define FOR(i,n) for(i=0;i<n;i++)

const int maxN = 200200;
ll ip[maxN];
int sum[maxN];
bool flag[20010000];

int main(){
  int i,n;
  scanf("%d",&n);
  FOR(i,n)
    scanf("%lld",&ip[i]);
  ll ans = 0;
  if(n <= 2000){
    set<ll> res;
    int l,r;
    FOR(l,n){
      ll S = 0;
      for(r=l; r<n; r++){
	S += ip[r];
	res.insert(S);
      }
    }
    ans = res.size();
  }
  else{
    sum[0] = 0;
    flag[0] = true;

    FOR(i,n){
      sum[i+1] = sum[i]+ip[i];
      flag[sum[i+1]] = true;
    }
    ll S = sum[n];
    for(i=1; i<=S; i++){
      if(!flag[i]){
	for(int j=1; j<=n; j++){
	  int cur = sum[j]+i;
	  if(flag[cur]){
	    flag[i] = true;
	    break;
	  }
	}
      }
      ans += flag[i];
    }
  }
  cout << ans-1 << endl;
  return 0;
}

