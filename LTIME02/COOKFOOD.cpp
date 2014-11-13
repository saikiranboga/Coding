#include<iostream>

using namespace std;

#define MOD 1000000007;
typedef long long int ll;

ll modpow(ll base, ll n){
  if(n==0){
    return 1;
  }
  else if(n == 1){
    return base%MOD;
  }
  else if(n%2 == 1){
    ll temp = modpow(base, n/2) ;
    ll ret = (temp*temp)%MOD;
    ret = (ret*base)%MOD;
    return ret;
  }
  else{
    ll temp = modpow(base, n/2);
    ll ret = (temp*temp)%MOD;
    return ret;
  }
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll i,n,k;
    ll ans = 1;
    cin >> n >> k;
    ans = (ans*k)%MOD;
    ans = (ans*(k-1))%MOD;
    n--;
    ll temp;
    ll tmp = k-2;
    temp = k-1 + (tmp*tmp)%MOD;
    temp = temp%MOD;
    ans = ( ans*modpow(temp, n) )%MOD;
    cout << ans << endl;
  }
  return 0;
}
