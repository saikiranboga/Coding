#include <iostream>
using namespace std;

#define MAX 260

int chrs[MAX];
long long int base;

long long int pow(long long int b, long long int p){
  if(p == 1)
    return b;
  else if(p == 0)
    return 1;
  else{
    long long int temp = pow(b,p/2);
    temp *= temp;
    if(p&1)
      return (temp*b);    
    else
      return temp;
  }
}

int main(){
  long long int t,i;
  cin >> t;
  string s;
  while(t--){

    for(i=0;i<MAX;i++)
      chrs[i] = -1;

    cin >> s;
    base = 2;
    chrs[ s[0] ] = 1;
    i = 1;
    if(s.length() > 1){
      while(i<s.length() && s[i] == s[0])
	i++;
      chrs[s[i]] = 0;

      for(i++;i<s.length();i++){
	if(chrs[ s[i] ] < 0){
	  chrs[ s[i] ] = base;
	  base++;
	}
      }

    }

    //    for(i=0;i<MAX;i++)
    //      if(chrs[i] >= 0)
    //	cout << (char)i << " " << chrs[i] << endl;

    long long int ans = 0;
    long long int tmp,p = 0;
    for(i=s.length()-1;i>=0;i--){
      ans += ( chrs[ s[i] ] *  pow(base,p));
      p++;
    }
    cout << ans << endl;
  }
  return 0;
}
