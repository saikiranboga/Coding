#include <iostream>

using namespace std;

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    int ar[n],dp[n];
    int max_t = 0;
    for(i=0;i<n;i++){
      cin >> ar[i];
      if(ar[i] > max_t)
	max_t = ar[i];
    }
    for(i=0;i<n;i++){
      cin >> dp[i];
      if(dp[i] > max_t)
	max_t = dp[i];
    }


    max_t += 1;
    int t,res = 0;
    for(t=0;t<=max_t;t++){
      int cur = 0;
      for(i=0;i<n;i++){
	cur += ( (ar[i] <= t) && (dp[i] > t) );
	res = max(res,cur);
      }
    }
    cout << res << endl;
  }
  return 0;
}
