#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b){
  return (*(int*)(a) - *(int*)(b));
}

int main(){
  int t,n;
  cin >> t;
  while(t--){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    qsort(a, n, sizeof(a[0]), compare);

    int curr = a[0];
    a[0] = 0;
    int count = 0;
    long long int ans = 0;
    int flag = 0;
    for(int i=1;i<n;i++){
      if(curr != a[i]){
	curr = a[i];
	a[i] = i;
	count++;
      }
      else{
	curr = a[i];
	a[i] = a[i-1];
      }
    }

    for(int i=1;i<n;i++)
      ans += a[i];

    cout << ans << endl;
  }
  return 0;
}
