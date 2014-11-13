#include <iostream>
#include <limits.h>
using namespace std;

int main(){
  long long int n,i;
  cin >> n;
  long long int a[n];
  long long int max = -1;
  for(i=0;i<n;i++){
    cin >> a[i];
    if(a[i]>max)
      max = a[i];
  }
  int sum[n];
  if(max <= 1){
    sum[n-1] = a[n-1];
    for(i=n-2;i>=0;i--)
      sum[i] = a[i]+sum[i+1];
  }
  long long int j;
  long long int ans = 0;
  if(max > 1){
    for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
	ans += a[i]&a[j];
    cout << ans << endl;
  }
  else{
    for(i=0;i<n-1;i++){
      ans += (a[i]*sum[i+1]);
    }
    cout << ans << endl;
  }
  return 0;
}
