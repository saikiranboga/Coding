#include <iostream>
#include <cstring>

using namespace std;

int main(){
  int i,j;
  int lett[26];
  memset(lett,0,26*sizeof(int));
  string s;
  cin >> s;
  int n = s.length();
  int rep;
  for(i=0;i<n;i++)
    lett[ s[i]-'a' ]++;
  for(i=0;i<26;i++){
    if(lett[i]){
      rep = lett[i]/2;
      for(j=0;j<rep;j++)
	cout << char(i+int('a'));
    }
  }
  cout << endl;
  return 0;
}
