#include <iostream>
#include <string.h>
using namespace std;

int main(){
  int t,i;
  cin >> t;
  string j,s;
  while(t--){
    cin >> j >> s;
    int upper_j[26],lower_j[26];
    memset( upper_j, 0, 26*sizeof(int) );
    memset( lower_j, 0, 26*sizeof(int) );

    int upper_s[26],lower_s[26];
    memset( upper_s, 0, 26*sizeof(int) );
    memset( lower_s, 0, 26*sizeof(int) );

    int len = j.length();
    char c;
    for(i=0;i<len;i++){
      c = j[i];
      if(c >= 'A' && c <= 'Z')
	upper_j[c-'A']++;
      else
	lower_j[c-'a']++;
    }

    len = s.length();

    for(i=0;i<len;i++){
      c = s[i];
      if(c >= 'A' && c <= 'Z')
	upper_s[c-'A']++;
      else
	lower_s[c-'a']++;
    }

    int ans = 0;
    for(i=0;i<26;i++){
      if(upper_j[i]>0)
	ans += upper_s[i];
      if(lower_j[i]>0)
	ans += lower_s[i];
    }
    cout << ans << endl;
  }
  return 0;
}
