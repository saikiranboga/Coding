#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int t,i,j,k,scores[101];
  cin >> t; 
  while(t--){
    memset(scores,0,101*sizeof(int));
    for(i=0;i<11;i++){
      cin >> k;
      scores[k]++;
    }
    cin >> k;
    for(i=100;;){
      if(scores[i] >= k){
	int a = 1, b = 1;
	for(j=0;j<k;j++){
	  a *= (scores[i]-j);
	  b *= (j+1);
	}
	cout << a/b << endl;
	break;
      }
      k -= scores[i--];
    }
  }
  return 0;
}
