#include <iostream>

using namespace std;

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    int x,l,f,x_p,l_p,f_p;
    cin >> x_p >> l_p >> f_p;
    int time = (x_p + l_p);
    for(i=1;i<n;i++){
      cin >> x >> l >> f;
      while(x < time){
	x += f;
      }
      time += (x-time + l);
    }
    cout << time << endl;
  }
  return 0;
}
