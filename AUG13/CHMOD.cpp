#include <iostream>

using namespace std;
typedef long long int ll;

int ar[100010];

int main(){
  int n,t,i,li,ri,mi;
  cin >> n;
  for(i=0; i<n; i++)
    cin >> ar[i];

  cin >> t;
  while(t--){
    cin >> li >> ri >> mi;
    li--;
    ri--;
    ll ans = 1;
    for(i=li;i<=ri;i++){
      ans = ( (ans%mi)*(ar[i])%mi )%mi;
    }
    cout << ans << endl;
  }
  return 0;
}
