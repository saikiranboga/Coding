#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000007

int main(){
  int t,n,m,i,j;
  cin >> t;
  while(t--){
    cin >> n >> m;
    int a[n];
    for(i=0;i<n;i++)
      a[i] = 1;
    int b[n],c[n],d[n];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(b));
    memset(d,0,sizeof(b));
    a[0] = 0;
    a[n-1] = 0;
    c[n-1] = 1;
    long long int ans = 0;
    for(j=0; j<m-1; j++){
      int a2[n],b2[n],c2[n],d2[n];
      memset(a2,0,sizeof(a2));
      memset(b2,0,sizeof(b2));
      memset(c2,0,sizeof(c2));
      memset(d2,0,sizeof(d2));

      for(i=1; i<n-1; i++){
	a2[i] = (a[i+1] + a[i-1])%MOD;
	b2[i] = (b[i+1] + b[i-1])%MOD;
	c2[i] = (c[i+1] + c[i-1])%MOD;
	d2[i] = (d[i+1] + d[i-1])%MOD;
      }
      b2[0] = (a[1] + b[1])%MOD;
      c2[n-1] = (a[n-2] + c[n-2])%MOD;
      d2[0] = (c[1] + d[1])%MOD;
      d2[n-1] = (b[n-2] + d[n-2])%MOD;

      memcpy(&a,&a2,sizeof(a));
      memcpy(&b,&b2,sizeof(b));
      memcpy(&c,&c2,sizeof(c));
      memcpy(&d,&d2,sizeof(d));
      long long int x = 0;
      for(i=0;i<n;i++){
	x = (x+d2[i])%MOD;
      }
      ans = (ans+x)%MOD;
    }
    ans = ans%MOD;
    cout << ans << endl;
  }  
  return 0;
}
