#include <iostream>

using namespace std;

int gcd(int a, int b){
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

int main(){
  int t,a,b,i;
  string s;
  cin >> t;
  while(t--){
    cin >> a;
    cin >> s;
    if(a == 0){
      cout << s << endl;
    }
    else{
      int rem = 0;
      int len = s.length();
      for(i=0;i<len;i++){
	rem = (rem*10 + (int)(s[i]-'0'))%a;
      }
      if(a>rem)
	cout << gcd(a,rem) << endl;
      else
	cout << gcd(rem,a) << endl;
    }
  }

  return 0;
}
