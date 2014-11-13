#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n){
    int a[n+1];
    int pos[n+1];
    for(register int i=1;i<=n;i++){
      cin >> a[i];
      pos[i] = a[i];
    }
    register int flag = 0;
    for(register int i=1;i<=n;i++){
      if(a[pos[i]] != i){
	flag = 1;
	break;
      }
    }
    if(flag&1)
      cout << "not ambiguous\n";    
    else
      cout << "ambiguous\n";
    cin >> n;
  }
  return 0;
}
