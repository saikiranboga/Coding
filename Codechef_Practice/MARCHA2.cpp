#include <iostream>

using namespace std;

int main(){
  int t,k,l,i;
  cin >> t;
  while(t--){
    cin >> k;
    int flag = 1;
    int lvs[k+1];
    for(i=1;i<=k;i++){
      cin >> lvs[i];
    }
    int n_stems = 1;
    for(i=1;i<=k;i++){
      l = lvs[i];
      if(l > n_stems){
	flag = 0;
	break;
      }
      n_stems = 2*(n_stems - l);
    }

    if(flag)
      if(n_stems){
	flag = 0;
      }

    if(flag)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
