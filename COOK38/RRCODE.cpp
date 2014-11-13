#include <iostream>
using namespace std;

typedef long long int ll;

int main(){
  ll t,n,k,ans,i,j;
  string s;
  cin >> t;
  while(t--){
    cin >> n >> k >> ans;
    ll ans1,ans2,ans3;
    ll temp;

    cin >> temp;

    ans1 = temp;
    ans2 = temp;
    ans3 = temp;
    for(i=1;i<n;i++){
      cin >> temp;
      ans1 = ans1 & temp;
      ans2 = ans2 ^ temp;
      ans3 = ans3 | temp;
    }
    cin >> s;
    if(k == 0)
      cout << ans << endl;
    else if(s[0] == 'X'){

      if(k%2 == 0)
	cout << ans << endl;
      else
	cout << (ans2 ^ ans) << endl;
    }
    else if(s[0] == 'A'){
      cout << (ans1 & ans) << endl;
    }
    else{
      cout << (ans3 | ans) << endl;
    }

  }
  return 0;
}
