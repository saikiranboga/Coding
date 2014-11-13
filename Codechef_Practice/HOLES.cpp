#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int holes[26] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
  int freq[26];
  int i,t;
  cin >> t;
  string str;
  while(t--){
    memset(freq,0,25*sizeof(int));
    cin >> str;
    for(i=0;i<str.length();i++)
      freq[str[i]-65]++;
    int ans = 0;
    for(i=0;i<26;i++)
      ans += holes[i]*freq[i];
    cout << ans << endl;
  }
  return 0;
}
