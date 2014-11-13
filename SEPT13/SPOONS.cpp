#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int ll;
int main(){
  int t;
  ll n;
  cin >> t;
  while(t--){
    cin >> n;
    if(n==2)
      cout << 2 << endl;
    else{
      ll x = (1+sqrt(1+8*n))/2;
      x += 2;
      ll temp = x*(x-1);
      while(temp >= 2*n){
	x--;
	temp = x*(x-1);
      }
      x++;
      cout << x << endl;
    }
  }
  return 0;
}
