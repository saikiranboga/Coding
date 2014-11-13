#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* a, const void* b){
  return ( *(int*)a - *(int*)b );
}

int main(){
  int t,n,i;
  cin >> t;
  while(t--){
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
      cin >> a[i];
    qsort(a,n,sizeof(int),compare);
    int min_diff = 1000000000;
    int diff;
    for(i=0;i<n-1;i++){
      diff = a[i+1]-a[i];
      min_diff = (diff<min_diff)?diff:min_diff;
    }
    cout << min_diff << endl;
  }
  return 0;
}
