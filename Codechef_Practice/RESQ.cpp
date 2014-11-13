#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int t,n,x,y;
  cin >> t;
  while(t--){
    cin >> n;
    int ans;
    for(x=floor(sqrt(n)); x >=1; x--){
      if(n%x == 0){
	y = n/x;
	ans = y-x;
	break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
