#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define pb push_back
#define mp make_pair

int main(){
  int t,n;
  cin >> t;
  while(t--){
    cin >> n;
    int H_men[n],H_wom[n];
    
    for(int i=0;i<n;i++)
      cin >> H_men[i];

    for(int i=0;i<n;i++)
      cin >> H_wom[i];

    sort(H_men,H_men+n);
    sort(H_wom,H_wom+n);

    LL ans = 0;
    for(int i=0;i<n;i++)
      ans += H_wom[i]*H_men[i];
    cout << ans << endl;
  }
  return 0;
}