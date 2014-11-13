#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

typedef long long int ll;

void quickSort(ll arr[], ll low, ll high){
  ll i = low;
  ll j = high;
  ll y = 0;
  ll z = arr[(low + high) / 2];
  do {
    while(arr[i] < z) i++;
    while(arr[j] > z) j--;
    if(i <= j) {
      y = arr[i];
      arr[i] = arr[j];
      arr[j] = y;

      i++;
      j--;
    }
  } while(i <= j);
  if(low < j)
    quickSort(arr, low, j);
  if(i < high)
    quickSort(arr, i, high);
}

int P[10010];
int c[110];
ll ar[110][110];

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,m,ci,i,j;
    cin >> n >> m;

    for(i=0;i<m;i++)
      cin >> P[i];
    
    for(i=0;i<n;i++){
      cin >> c[i];
      for(j=0;j<c[i];j++){
	cin >> ar[i][j];
      }
      quickSort(ar[i],0,c[i]-1);
    }
    ll ans = 0;
    for(i=0;i<m;i++){
      if(c[ P[i] ] >= 1){
	ans += ar[P[i]][c[ P[i] ]-1];
	c[ P[i] ]--;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
