#include <iostream>
using namespace std;

#define ll long long int

void quickSort(ll arr[],ll idx[], ll idx2[], ll low, ll high){
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

      y = idx[i];
      idx[i] = idx[j];
      idx[j] = y;
      
      y = idx2[i];
      idx2[i] = idx2[j];
      idx2[j] = y;

      i++;
      j--;
    }
  } while(i <= j);
  if(low < j)
    quickSort(arr, idx, idx2, low, j);
  if(i < high)
    quickSort(arr, idx, idx2, i, high);
}

int main(){
  ll t,i,n,j;
  cin >> t;
  while(t--){
    cin >> n;
    ll pos[n];
    ll ln[n];
    ll idx[n];
    for(i=0;i<n;i++){
      cin >> pos[i] >> ln[i];
      idx[i] = i;
    }
    quickSort(pos,ln,idx,0,n-1);
    ll as[100010];
    for(i=0;i<n;i++){
      ll ans = 1;
      ll max = ln[i];
      j = i;
      while( j+1 < n && max > (pos[j+1]-pos[j])){
	ans++;
	max = ln[j+1]>(ln[j]-pos[j+1]+pos[j])?ln[j+1]:(ln[j]-pos[j+1]+pos[j]);
	j++;
      }
      as[idx[i]] = ans;
    }
    for(i=0;i<n;i++)
      cout << as[i] << " ";
    cout << endl;
  }
  return 0;
}
