#include <iostream>

using namespace std;

int main(){
  int t,p,q,r,r_bitcount;
  cin >> t;
  while(t--){
    cin >> p;
    q = p/2048;
    r = p%2048;
    r_bitcount = 0;
    while(r){
      r_bitcount++;
      r &= r-1;
    }
    cout << (q+r_bitcount) << endl;
  }
  return 0;
}
