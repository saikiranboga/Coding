#include <iostream>
using namespace std;

int main(){

  int t;
  cin >> t;
  while(t--){
    double d,u,n,m,r,c;
    int i,ans = 0;
    cin >> d >> u >> n;
    double cost,best = u*d;
    for(i=0;i<n;i++){
      cin >> m >> r >> c;
      cost = c/m + u*r;
      if(cost < best){
	best = cost;
	ans = i+1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
