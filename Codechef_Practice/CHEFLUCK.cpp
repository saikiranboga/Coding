#include <iostream>

using namespace std;

int main(){
  int t,n,r,q,c4;
  cin >> t;
  while(t--){
    cin >> n;
    r = n%7;
    q = n/7;
    switch(r){
    case 0:
      {
	c4 = 7*q;
	break;
      }
    case 1:
      {
	c4 = 7*(q-1);
	break;
      }
    case 2:
      {
	c4 = 7*(q-2);
	break;
      }
    case 3:
      {
	c4 = 7*(q-3);
	break;
      }
    case 4:
      {
	c4 = 7*q;
	break;
      }
    case 5:
      {
	c4 = 7*(q-1);
	break;
      }
    case 6:
      {
	c4 = 7*(q-2);
	break;
      }
    }

    if(c4 < 0)
      cout << -1 << endl;
    else
      cout << c4 << endl;

  }
  return 0;
}
