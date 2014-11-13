#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  int t;
  cin >> t;
  long long int ans;
  while(t--){
    long long int n,i;
    cin >> n;
    ans = 0;
    for(i=1;i*i<=n;i++)
      ans += (n/i);
    i--;
    ans = 2*ans - i*i;
    long long int g = __gcd(ans,n*n);
    cout<< ans/g << "/" << (n*n)/g << endl;
  }
return 0;
}
