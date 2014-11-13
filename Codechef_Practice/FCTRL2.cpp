#include <iostream>

using namespace std;

int main(){
  int t,n,i,j,x,temp,m;
  cin >> t;
  while(t--){
    cin >> n;
    int a[200];
    a[1] = 1;
    m = 1;

    for(i=1; i<=n; i++){
      for( temp = 0, j=1;j<=m;j++){
	x = temp + (a[j]*i);
	a[j] = x%10;
	temp = x/10;
      }
      while(temp > 0){
	a[++m] = temp%10;
	temp /= 10;
      }
    }

    for(i=m;i>0;i--){
      cout << a[i];
    }
    cout << endl;
  }
  return 0;
}
