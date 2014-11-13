#include <iostream>
using namespace std;

#define M 10000009

int main(){
  int t,i;
  string s;
  cin >> t;
  while(t--){
    cin >> s;
    int len = s.length();
    int ans = 1;

    for(i=0;i<len/2;i++){
      if(s[i] == '?' && s[len-1-i] == '?')	
	ans = (ans*26)%M;
      else if(s[i] == '?' || s[len-1-i] == '?')
	;
      else if(s[i] != s[len-1-i]){
	ans = 0;
	break;
      }
    }
    if( len&1 )
      if(s[len>>1] == '?')
	ans = (ans*26)%M;
    cout << ans << endl;
  }
  return 0;
}
