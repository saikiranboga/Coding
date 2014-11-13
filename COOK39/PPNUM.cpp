#include <iostream>
#include <cmath>

using namespace std;

#define M 1000000007

int main(){
  long long int t,l,r,p,n,tmp,s,sum,d;
  cin >> t;
  while(t--){
    cin >> l >> r;
    d = 0;
    tmp = l;
    while( tmp>0 ){
      d++;
      tmp /= 10;
    }
    n = d;
    sum = 0;
    s = l;
    n = pow(10,n);
    if( n>=r ){
      sum = (((r-l+1)*(r+l))/2)*d;
      cout << (sum%M) << endl;
    }
    else{
      while( n<=r ){
	sum = (sum+(((n-s)*(n+s-1)/2)*d)%M)%M;
	s = n;
	n = n*10;
	d = d+1;
      }
      n = n/10;
      sum = (sum+((  (r-n+1)*(2*n+(r-n)) /2)*d)%M)%M;
      cout << sum << endl;
    }
  }
}
