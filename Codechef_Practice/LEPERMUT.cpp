#include <iostream>

using namespace std;

int main(){
  int t,n,i,j;
  cin >> t;
  while(t--){
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
      cin >> a[i];
    int local = 0,global = 0;
    for(i=0;i<n-1;i++)
      if(a[i]>a[i+1])
	local++;
    for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
	if(a[i] > a[j])
	  global++;
    if(local == global)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
