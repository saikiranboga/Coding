#include <iostream>
using namespace std;

long long int f(long long int n){
  long long int res;

  if(n>=0){
    res = (n+3)*(n+2)*(n+1);
    res /= 6;
    return res;
  }
  else{
    return 0;
  }

}

int main(){
  long long int t,a,b,c,d,n;
  cin >> t;
  while(t--){
    cin >> n >> a >> b >> c;
    long long int ans;
    ans = f(n) - f(n-(a+1)) - f(n-(b+1)) - f(n-(c+1)) + f(n-(a+b+2)) + f(n-(b+c+2)) + f(n-(c+a+2)) - f(n-(a+b+c+3));
    cout << ans << endl;
  }
  return 0;
}
