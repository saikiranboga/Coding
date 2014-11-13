#include <iostream>
#include <sstream> 
#include <vector> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <string> 
#include <cstring>
#include <cstdio> 

using namespace std;
int n,k,q,i,j,x;
int Q[1000000];
 
int main(){
  int T;
  cin >> T;
  while (T--){
    cin >> n >> k;
    q = 0;
    for (i=1;i<=n;i++) {
      cin >> x;  
      for (j=i-k+1;j>1;j-=k){
	q++;
	Q[q] = j;
      }
      q++;
      Q[q] = 1;
    }
    cout << q << endl;
    for (i=1;i<q;i++) printf("%d ", Q[i]);
    cout << Q[q] << endl;
  }
  return 0;
}
