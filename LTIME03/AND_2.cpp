#include <iostream>
#include <cstring>

using namespace std;

int main(){
  long long int n,i,j;
  cin >> n;
  long long int a[n];
  long long int bits[30];
  memset(bits,0,sizeof(bits));
  for(i=0;i<n;i++){
    cin >> a[i];
    for(j=0;j<30;j++)    
      if(a[i]&(1<<j))
	bits[j]++;
  }
  long long int ans = 0;
  for(j=0;j<30;j++)
    ans += (bits[j]*(bits[j]-1))*(1<<j);
  cout << ans/2 << endl;
  return 0;
}
