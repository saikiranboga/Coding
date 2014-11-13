#include <iostream>
#include <algorithm>
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
  int t,n,k,i,j;
  cin >> t;
  while(t--){
    cin >> n >> k;
    int a[n],b[n];
    for(i=0;i<n;i++)
      cin >> a[i];
    for(i=0;i<n;i++)
      cin >> b[i];
    quickSort(a,0,n-1);
    quickSort(b,0,n-1);
    for(i=0;i<n;i++){
      if(a[i]+b[n-i-1] < k){
	cout << "NO\n";
	break;
      }
    }
    if(i==n)
      cout << "YES\n";
  }
  return 0;
}
