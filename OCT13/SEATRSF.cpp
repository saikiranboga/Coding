#include <iostream>
using namespace std;

#define ll long long int
#define M 1000000007

int main(){
  ll t,n,m,q,k,i,j;
  //  cout << 1000000000LL*1000000000LL << endl;
  cin >> t;
  while(t--){
    cin >> n >> m >> q >> k;
    i = 1;
    ll ans1 = -1, ans = 0;
    while(q+i <= m){
      ans1 = (n*(n-1)/2)%M;
      for(j=0;j<n-2;j++)
	ans1 = ( (ans1%M)*((q+1)%M) )%M;
      ans = ( (ans%M) + (ans1)%M )%M;
      i++;
    }
    if(n == 1 || ans1<0){
      cout << 0 << endl;
    }
    else{
      cout << ans << endl;
    }
  }
  return 0;
}
