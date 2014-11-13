#include <iostream>

using namespace std;

int main(){
  int t,n,a,b;
  cin >> t;
  while(t--){
    cin >> n >> a >> b;
    int num1_a = 0;
    int num1_b = 0;
    while(a){
      a = a&(a-1);
      num1_a++;
    }
    while(b){
      b = b&(b-1);
      num1_b++;
    }

    int num0_a = n-num1_a;
    int num0_b = n-num1_b;

    int p = min(num1_a,num0_b) + min(num1_b,num0_a);

    int ans = ( (1<<p)-1 )<<(n-p);
    cout << ans << endl;
  }
  return 0;
}
