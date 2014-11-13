#include <iostream>

using namespace std;

void quickSort(int arr[], int low, int high){
  int i = low;
  int j = high;
  int y = 0;
  int z = arr[(low + high) / 2];
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


int main(){
  int i,n,k;
  cin >> n >> k;
  int ar[n];
  for(i=0;i<n;i++)
    cin >> ar[i];
  quickSort(ar,0,n-1);
  int ans = 0;
  i = 0;
  while(k>0){
    if(ar[i] <= k){
      ans++;
      k -= ar[i];
      i++;
    }
    else{
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
