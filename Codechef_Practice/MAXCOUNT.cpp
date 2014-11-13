#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int t,n,i,temp;
  cin >> t;
  while(t--){
    cin >> n;
    int freq[10001];
    memset(freq,0,10001*sizeof(int));

    for(i=0;i<n;i++){
      cin >> temp;
      freq[temp]++;
    }
    int max_f = 0;
    int max_n;
    for(i=1;i<=10000;i++){
      if(freq[i] > max_f){
	max_f = freq[i];
	max_n = i;
      }
    }
    cout << max_n << " " << max_f << endl;
  }
  return 0;
}
