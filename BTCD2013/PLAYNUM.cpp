#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define ll long long int
int compare(const void * a, const void * b){
  return (*(int *)b - *(int *)a);
}

int main(){
  int t,n,q,i,a,b;
  cin >> t;
  while(t--){
    cin >> n;
    cin >> q;
    int ar[n],freq[n];
    ll ans = 0;
    memset(freq,0,n*sizeof(freq[0]));
    for(i=0;i<n;i++)
      cin >> ar[i];        
    while(q--){
      cin >> a;
      cin >> b;      
      for(i=a-1;i<b;i++)
	freq[i]++;
    }
    qsort(freq,n,sizeof(freq[0]),compare);
    qsort(ar,n,sizeof(ar[0]),compare);

    for(i=0;i<n;i++){
      ans += (freq[i]*ar[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
