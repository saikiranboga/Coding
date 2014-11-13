#include <iostream>
#include <cstring>

using namespace std;
/*
int count[200001];
int SL[10000][10000];
void substr(string s1, string s2){
  int l1 = s1.length();
  int l2 = s2.length();
  int i,j;
  for(i=0; i<l1; i++){
    for(j=0; j<l2; j++){
      if(s1[i] == s2[j]){
	count[1]++;
	if(i==0 || j==0)
	  SL[i][j] = 1;
	else{
	  SL[i][j] = SL[i-1][j-1]+1;
	  count[SL[i][j]]++;
	}
      }
      else{
	SL[i][j] = 0;
      }
    }
  }
}
*/
int main(){
  int t,i,j;
  cin >> t;
  while(t--){
    int L;
    string s1,s2;
    cin >> s1 >> s2 >> L;
    //    for(i=0;i<200001;i++)
    //      count[i] = 0;
    //    substr(s1, s2);
    //    for(i=1;i<L;i++)
    //      cout << count[i] << " ";
    if(L==1){
      if(s1[0] == s2[0])
	cout << 1 << endl;
    }
      cout << count[L] << endl;
  }
  return 0;
}
