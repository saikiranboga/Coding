#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;

long long gcd(long long a,long long b){
  if(a%b==0){return b;}
  else{return gcd(b,a%b);
  }
}

int main(){
  ll t,n,m,ans;
  cin >> t;
  while(t--){
    cin >> n >> m;
    if(n == m)
      ans = n;
    else if(n == 1)
      ans = m;
    else if(m == 1)
      ans = n;
    else{
      ans = gcd(m-1,n-1) + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
