#include <iostream>
using namespace std;

#define M 1000000007
#define N 100
long long int a[N+1];
void calc(){
  a[1] = 1;
  for(int i=2;i<=N;i++)
    a[i] = ( (2*i-1)*a[i-1] )%M;
}
int main(){
  int t,n;
  cin >> t;
  calc();
  while(t--){
    cin >> n;
    cout << a[n] <<  endl;
  }
  return 0;
}
