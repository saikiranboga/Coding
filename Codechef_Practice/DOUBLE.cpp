#include <iostream>

using namespace std;

int main(){
  int t,n;
  cin >> t;
  while(t--){
    cin >> n;
    if(n&1)
      cout << n-1 << endl;
    else
      cout << n << endl;
  }
}
