#include<iostream>
using namespace std;

typedef long long int ll;

int main(){
  ll t,N,K,a,b;
  cin >> t;
  while(t--){
    cin >> N >> K;
    if(K == 0){
      cout << 0 << " " << N << endl;
    }
    else{
      a = N/K;
      b = N%K;
      cout << a << " " << b << endl;
    }
  }
  return 0;
}
