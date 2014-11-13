#include <iostream>

using namespace std;

int main(){
  int t,n,c,ak,i;
  cin >> t;
  while(t--){
    cin >> n >> c;
    int sum = 0;
    for(i=0;i<n;i++){
      cin >> ak;
      sum += ak;
    }
    if(sum <= c)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
