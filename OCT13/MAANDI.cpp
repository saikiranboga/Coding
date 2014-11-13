#include <iostream>
#include <math.h>
using namespace std;

int overLucks[100000];

int check(int n){
  while(n > 0){
    if(n%10 == 4 || n%10 == 7){
      return 1;
    }
    n /= 10;
  }
  return 0;
}

int main(){
  int t,n,i,max,ans,num;
  cin >> t;
  while(t--){
    cin >> n;
    max = sqrt(n);
    ans = 0;
    for(i=1;i<=max;i++){
      if(n%i == 0){
	if(check(i)){
	  ans++;
	}
	num = n/i;
	if(num != i){
	  if(check(num))
	    ans++;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
