#include <iostream>
using namespace std;

int total;

struct vote{
  string name;
  int vot;
}votes[101];

int find(string s){
  if(total == 0)
    return -1;
  else{
    int i;
    for(i=1;i<=total;i++)
      if(votes[i].name == s)
	return i;
    return -1;      
  }
}

void print(){
  int i;
  int ans = 0;
  for(i=1;i<=total;i++)
    //    cout << votes[i].name << " " << votes[i].vot << endl;
    ans += votes[i].vot;
  cout << ans << endl;
}

int main(){
  int t,i,n,idx;
  cin >> t;
  while(t--){
    cin >> n;
    string s;
    char c;
    total = 0;
    for(i=0;i<n;i++){
      cin >> s >> c;
      idx = find(s);
      if(idx > 0){
	if(c == '+')
	  votes[idx].vot = 1;
	else
	  votes[idx].vot = -1;
      }
      else{
	votes[++total].name = s;
	if(c == '+')
	  votes[total].vot = 1;
	else
	  votes[total].vot = -1;
      }
    }
    print();
  }
  return 0;
}
